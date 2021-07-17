#ifndef C_BoxCollider_hpp
#define C_BoxCollider_hpp

#include "Component.hpp"
#include "C_Collider.hpp"

class C_BoxCollider : public C_Collider
{
    public:
        C_BoxCollider(Object* owner);

        Manifold Intersects(std::shared_ptr<C_Collider> other) override;
        void ResolveOverlap(const Manifold& manifold) override;

        void SetCollidable(const sf::FloatRect& rect);
        void SetOrigin(const float origin);
        void SetOrigin(const float originX, const float originY);
        const sf::FloatRect& GetCollidable();

    private:
        void SetPosition();

        sf::FloatRect AABB;
        sf::Vector2f offset;
};

#endif /* C_BoxCollider_hpp */