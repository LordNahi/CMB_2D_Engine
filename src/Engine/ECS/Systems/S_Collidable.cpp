#include "S_Collidable.hpp"

S_Collidable::S_Collidable()
{
    Bitmask defaultCollisions;
    defaultCollisions.SetBit(static_cast<int>(CollisionLayer::Default));
    collisionLayers.insert(std::make_pair(CollisionLayer::Default, defaultCollisions));

    Bitmask playerCollisions;
    playerCollisions.SetBit(static_cast<int>(CollisionLayer::Default));
    playerCollisions.SetBit(static_cast<int>(CollisionLayer::Tile));
    collisionLayers.insert(std::make_pair(CollisionLayer::Player, playerCollisions));
}

void S_Collidable::Add(std::shared_ptr<Object>& object)
{
    auto collider = object->GetComponent<C_BoxCollider>();

    if (collider)
    {
        CollisionLayer layer = collider->GetLayer();

        const auto itr = collidables.find(layer);

        if (itr != collidables.end())
        {
            collidables[layer].push_back(collider);
        }
        else
        {
            std::vector<std::shared_ptr<C_BoxCollider>> objs;
            objs.emplace_back(collider);

            collidables.insert(std::make_pair(layer, objs));
        }
    }
}

void S_Collidable::Add(std::vector<std::shared_ptr<Object>>& objects)
{
    for (auto& object : objects)
    {
        Add(object);
    }
}

void S_Collidable::ProcessRemovals()
{
    for (auto& layer : collidables)
    {
        auto itr = layer.second.begin();
        if (itr != layer.second.end())
        {
            auto obj = *itr;

            if (obj->owner->GetIsRemoving())
            {
                itr = layer.second.erase(itr);
            }
            else
            {
                ++itr;
            }
        }
    }
}

void S_Collidable::Update()
{
    collisionTree.DrawDebug();

    collisionTree.Clear();

    for (auto maps = collidables.begin(); maps != collidables.end(); ++maps)
    {
        for (auto collidable : maps->second)
        {
            collisionTree.Insert(collidable);
            Debug::DrawRect(collidable->GetCollidable(), sf::Color::Green);
        }
    }

    Resolve();
}

void S_Collidable::Resolve()
{
    for (auto maps = collidables.begin(); maps != collidables.end(); ++maps)
    {
        // This first loop is taking us through each layer and 


        /**
         * If `GetMask()` yields a 0, it means there were no set
         * bits, which means this layer was told not to collide with
         * any other layer, so we can just skip any furter checks
         * and `continue` to the next iteration ...
         */
        if (collisionLayers[maps->first].GetMask() == 0)
        {
            continue;
        }

        /**
         * As we are colliding with another layer (or layers), we
         * iterate through all collidable components of that layer
         * which are contained in `maps->second` ...
         */
        for (auto layerCollidable : maps->second)
        {
            /**
             * As static entities aren't moving, we dont need
             * to resolve their overlap ...
             */
            if (layerCollidable->owner->transform->GetIsStatic())
            {
                continue;
            }


            std::vector<std::shared_ptr<C_BoxCollider>> quadtreeResults
                = collisionTree.Search(layerCollidable->GetCollidable());

            for (auto quadtreeCollidable : quadtreeResults)
            {
                // Make sure we don't resolve collisions between the same object ...
                if (layerCollidable->owner->instanceID->Get() == quadtreeCollidable->owner->instanceID->Get())
                {
                    continue;
                }

                bool doLayersCollide = collisionLayers[layerCollidable->GetLayer()].GetBit(static_cast<int>(quadtreeCollidable->GetLayer()));

                if (doLayersCollide) 
                {
                    /**
                     * At this point we've established that the quadtree has
                     * given us back some potential collisions and atleast
                     * some of those collisions have occured on a layer that
                     * clashes with the current layer we're checking for ...
                     */

                    Manifold m = layerCollidable->Intersects(quadtreeCollidable);

                    if (m.colliding)
                    {
                        Debug::DrawRect(layerCollidable->GetCollidable());
                        Debug::DrawRect(quadtreeCollidable->GetCollidable());

                        if (quadtreeCollidable->owner->transform->GetIsStatic())
                        {
                            layerCollidable->ResolveOverlap(m);
                        }
                        else
                        {
                            // TODO: How shold we deal with collisions between two objects
                            // that are not static? ...
                            layerCollidable->ResolveOverlap(m);
                        }
                    }
                }
            }
        }
    }
}