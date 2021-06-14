#ifndef S_Collidable_hpp
#define S_Collidable_hpp

#include <vector>
#include <memory>
#include <set>

#include "Object.hpp"
#include "Quadtree.hpp"
#include "Bitmask.hpp"

class S_Collidable
{
    public:
        S_Collidable();

        void Add(std::vector<std::shared_ptr<Object>>& objects);
        void Add(std::shared_ptr<Object>& object);
        void ProcessRemovals();
        void Update();

    private:
        void Resolve();
        void ProcessCollision(std::vector<std::shared_ptr<Object>>& first, std::vector<std::shared_ptr<Object>>& second);

        // Used to store collision layer data; ie. which layers can collide ...
        std::map<CollisionLayer, Bitmask> collisionLayers;

        // The collision system stores all collidables along their layer ...
        std::map<CollisionLayer, std::vector<std::shared_ptr<C_BoxCollider>>> collidables;

        // The quadtree stores the collidables in a spatial aware structure ...
        Quadtree collisionTree;
};

#endif /* S_Collidable_hpp */