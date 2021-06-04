#ifndef C_Collider_hpp
#define C_Collider_hpp

#include <memory>
#include <SFML/Graphics.hpp>

#include "Component.hpp"

enum class CollisionLayer
{
    Default = 1,
    Player = 2,
    Tile = 3
};

struct Manifold
{
    bool colliding = false;
    const sf::FloatRect* other;
};

class C_Collider : public Component
{
    public:
        C_Collider(Object* owner);
        ~C_Collider();

        virtual Manifold Intersects(std::shared_ptr<C_Collider> other) = 0;
        virtual void ResolveOverlap(const Manifold& manifold) = 0;

        const CollisionLayer GetLayer();
        void SetLayer(CollisionLayer layer);

    private:
        CollisionLayer layer;
};

#endif /* C_Collider_hpp */