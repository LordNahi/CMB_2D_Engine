#include <cmath>

#include "C_BoxCollider.hpp"
#include "Object.hpp"

C_BoxCollider::C_BoxCollider(Object* owner)
:
C_Collider(owner),
offset(sf::Vector2f(0.f, 0.f))
{}

void C_BoxCollider::SetCollidable(const sf::FloatRect& rect)
{
    AABB = rect;
    SetPosition();
}

const sf::FloatRect& C_BoxCollider::GetCollidable()
{
    SetPosition();
    return AABB;
}

void C_BoxCollider::SetPosition()
{
    // TODO: May need to factor transform origin into this formula ...
    // TODO: May also need to factor transform scale in ...

    const sf::Vector2f& pos = owner->transform->GetPosition();

    AABB.left = pos.x - (AABB.width / 2) + offset.x;
    AABB.top = pos.y - (AABB.height / 2) + offset.y;
}

Manifold C_BoxCollider::Intersects(std::shared_ptr<C_Collider> other)
{
    Manifold m;
    m.colliding = false; // We default to not colliding ...

    auto boxCollider = std::dynamic_pointer_cast<C_BoxCollider>(other);

    if (boxCollider)
    {
        const sf::FloatRect& rect1 = GetCollidable();
        const sf::FloatRect& rect2 = boxCollider->GetCollidable();

        if (rect1.intersects(rect2))
        {
            m.colliding = true;
            m.other = &rect2;
        }
    }

    return m;
}

void C_BoxCollider::ResolveOverlap(const Manifold& m)
{
    auto transform = owner->transform;

    if (transform->GetIsStatic()) { return; }

    const sf::FloatRect& rect1 = GetCollidable();
    const sf::FloatRect* rect2 = m.other;

    float resolve = 0;
    float xDiff = (rect1.left + (rect1.width * 0.5f))
        - (rect2->left + (rect2->width * 0.5f));
    float yDiff = (rect1.top + (rect1.height * 0.5f))
        - (rect2->top + (rect2->height * 0.5));

    if (fabs(xDiff) > fabs(yDiff))
    {
        if (xDiff > 0) // Colliding on the left ...
        {
            resolve = (rect2->left + rect2->width) - rect1.left;
        }
        else // Colliding on the right ...
        {
            resolve = -((rect1.left + rect1.width) - rect2->left);
        }

        transform->AddPosition(resolve, 0);
    }
    else
    {
        if (yDiff > 0) // Colliding above ...
        {
            // We add a positive y value to move the object down ...
            resolve = (rect2->top + rect2->height) - rect1.top;
        }
        else // Colliding below ...
        {
            resolve = -((rect1.top + rect1.height) - rect2->top);
        }

        transform->AddPosition(0, resolve);
    }
}