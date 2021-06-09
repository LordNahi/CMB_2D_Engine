#include "Quadtree.hpp"

Quadtree::Quadtree() : Quadtree(5, 5, 0, {0.f, 0.f, 1920, 1080}, nullptr) {}

Quadtree::Quadtree(
    int maxObjects,
    int maxLevels,
    int level,
    sf::FloatRect bounds,
    Quadtree* parent)
:
maxObjects(maxObjects),
maxLevels(maxLevels),
level(level),
bounds(bounds),
parent(parent)
{}

void Quadtree::Insert(std::shared_ptr<C_BoxCollider> object)
{
    if (children[0] != nullptr) // If we've split ...
    {
        int indexToPlaceObject = GetChildIndexForObject(object->GetCollidable());

        if (indexToPlaceObject != thisTree)
        {
            children[indexToPlaceObject]->Insert(object);
            return;
        }
    }

    objects.emplace_back(object);

    if (objects.size() > maxObjects && level < maxLevels && children[0] == nullptr)
    {
        Split();

        auto objIterator = objects.begin();
        while (objIterator != objects.end())
        {
            auto obj = *objIterator;
            int indexToPlaceObject = GetChildIndexForObject(obj->GetCollidable());

            if (indexToPlaceObject != thisTree)
            {
                children[indexToPlaceObject]->Insert(obj);
                objIterator = objects.erase(objIterator);
            }
            else
            {
                ++objIterator;
            }
        }
    }
}

void Quadtree::Remove(std::shared_ptr<C_BoxCollider> object)
{
    int index = GetChildIndexForObject(object->GetCollidable());

    if (index == thisTree || children[index] == nullptr)
    {
        for (int i = 0; i < objects.size(); i++)
        {
            if (objects.at(i)->owner->instanceID->Get() == object->owner->instanceID->Get())
            {
                objects.erase(objects.begin() + i);
                break;
            }
        }
    }
    else
    {
        return children[index]->Remove(object);
    }
}

void Quadtree::Clear()
{
    // Using smart pointers so this should free up
    // our memory too ...
    objects.clear();

    for (int i = 0; i < 4; i++)
    {
        auto node = children[i];

        if (node)
        {
            node->Clear();
            node = nullptr;
        }
    }
}

std::vector<std::shared_ptr<C_BoxCollider>> Quadtree::Search(const sf::FloatRect& area)
{
    std::vector<std::shared_ptr<C_BoxCollider>> possibleOverlaps;
    
    Search(area, possibleOverlaps);

    std::vector<std::shared_ptr<C_BoxCollider>> results;

    for (auto collider : possibleOverlaps)
    {
        if (area.intersects(collider->GetCollidable()))
        {
            results.emplace_back(collider);
        }
    }

    return results;
}

void Quadtree::Search(const sf::FloatRect& area, std::vector<std::shared_ptr<C_BoxCollider>>& overlappingobjects)
{
    /**
     * NOTE: I had a hard time understanding this logic initially, but
     * I'll explain it for my own brain's sanity ...
     * 
     * We begin by inserting all of the colliders from the current node
     * into our overlappingObjects vector.
     * 
     * We Then check if the current node has split, if so we call our
     * `GetChildIndexForObject` function, this will give us the index
     * of the child the area is within, if it can't find a perfect
     * match, it means we're intersecting multiple quads and will then
     * iterate through each child and check are intersecting and call
     * `Search` if true. 
     */

    overlappingobjects.insert(overlappingobjects.end(), objects.begin(), objects.end());

    if (children[0] != nullptr) // If we've split ...
    {
        int index = GetChildIndexForObject(area);

        if (index == thisTree)
        {
            for (int i = 0; i < 4; i++)
            {
                if (children[i]->GetBounds().intersects(area))
                {
                    children[i]->Search(area, overlappingobjects);
                }
            }
        }
        else
        {
            children[index]->Search(area, overlappingobjects);
        }
    }
}

const sf::FloatRect& Quadtree::GetBounds() const
{
    return bounds;
}

int Quadtree::GetChildIndexForObject(const sf::FloatRect& objectBounds)
{
    int index = -1;

    double verticalDividingLine  = bounds.left + bounds.width  * 0.5f;
    double horizonalDividingLine = bounds.top  + bounds.height * 0.5f;

    bool north = objectBounds.top < horizonalDividingLine
        && (objectBounds.top + objectBounds.height < horizonalDividingLine);
    bool south = objectBounds.top >= horizonalDividingLine;
    bool west = objectBounds.left < verticalDividingLine
        && (objectBounds.left + objectBounds.width < verticalDividingLine);
    bool east = objectBounds.left >= verticalDividingLine;

    if (east)
    {
        if (north)
        {
            return childNE;
        }
        else if (south)
        {
            return childSE;
        }
    }

    if (west)
    {
        if (north)
        {
            return childNW;
        }
        else if (south)
        {
            return childSW;
        }
    }

    // Area fits within no quad, return the index as is ...
    return index;
}

void Quadtree::Split()
{
    float childWidth = bounds.width / 2;
    float childHeight = bounds.height / 2;

    children[childNE] = std::make_shared<Quadtree>(maxObjects, maxLevels, level + 1,
        sf::FloatRect(bounds.left + childWidth, bounds.top, bounds.left + bounds.width, bounds.top + childHeight), this);
    children[childNW] = std::make_shared<Quadtree>(maxObjects, maxLevels, level + 1,
        sf::FloatRect(bounds.left, bounds.top, bounds.left + childWidth, bounds.top + childHeight), this);
    children[childSE] = std::make_shared<Quadtree>(maxObjects, maxLevels, level + 1,
        sf::FloatRect(bounds.left + childWidth, bounds.top + childHeight, bounds.left + bounds.width, bounds.top + bounds.height), this);
    children[childSW] = std::make_shared<Quadtree>(maxObjects, maxLevels, level + 1,
        sf::FloatRect(bounds.left, bounds.top + childHeight, bounds.left + childWidth, bounds.top + bounds.height), this);
}