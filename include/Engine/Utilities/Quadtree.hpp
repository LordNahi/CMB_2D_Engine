#ifndef Quadtree_hpp
#define Quadtree_hpp

#include <memory>
#include <vector>

#include "C_BoxCollider.hpp"
#include "Object.hpp"

class Quadtree
{
    public:
        Quadtree();
        Quadtree(
            int maxobjects,
            int maxLevels,
            int level,
            sf::FloatRect bounds,
            Quadtree* parent);

        // Insert a new object to be collision checked ...
        void Insert(std::shared_ptr<C_BoxCollider> object);

        // Remove object when we no longer want to check it for collision ...
        void Remove(std::shared_ptr<C_BoxCollider> object);

        // Remove all objects from tree ...
        void Clear();

        // Returns vector of colliders that intersect with the `area` ...
        std::vector<std::shared_ptr<C_BoxCollider>> Search(const sf::FloatRect& area);

        // Returns the bounds of this node ...
        const sf::FloatRect& GetBounds() const;
    
    private:
        void Search(
            const sf::FloatRect& area,
            std::vector<std::shared_ptr<C_BoxCollider>>& overlappingObjects);

        // Returns the index for the node that will contain
        // the object. -1 is returns if it is this node ...
        int GetChildIndexForObject(const sf::FloatRect& objectBounds);

        // Creates the child nodes ...
        void Split();

        // Indices for our array of children ...
        static const int thisTree = -1;
        static const int childNE = 0;
        static const int childNW = 1;
        static const int childSW = 2;
        static const int childSE = 3;

        int maxObjects;
        int maxLevels;

        // Root node will maintain a nullptr ...
        Quadtree* parent;
        std::shared_ptr<Quadtree> children[4];

        // Stores object in this node ...
        std::vector<std::shared_ptr<C_BoxCollider>> objects;

        // How feep the current node is in relation to the
        // base node. The firs tnode starts at 0 and the its
        // child node is at level 1 and so on ...
        int level;

        // The bounds of this node ...
        sf::FloatRect bounds;
};

#endif /* Quadtree_hpp */