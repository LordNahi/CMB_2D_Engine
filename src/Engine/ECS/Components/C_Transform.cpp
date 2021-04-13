#include "C_Transform.hpp"

Transform::Transform(Object* owner)
    : Component(owner), position(0.f, 0.f) { }

void Transform::SetPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

void Transform::SetPosition(const sf::Vector2f pos)
{
    position = pos;
}

void Transform::AddPosition(float x, float y)
{
    position.x += x;
    position.y += y;
}

void Transform::AddPosition(const sf::Vector2f pos)
{
    position += pos;
}

void Transform::SetX(float x)
{
    position.x = x;
}

void Transform::SetY(float y)
{
    position.y = y;
}

void Transform::AddX(float x)
{
    position.x += x;
}

void Transform::AddY(float y)
{
    position.y += y;
}

const sf::Vector2f& Transform::GetPosition() const
{
    return position;
}