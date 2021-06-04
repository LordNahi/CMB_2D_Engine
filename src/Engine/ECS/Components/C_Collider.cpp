#include "C_Collider.hpp"

C_Collider::C_Collider(Object* owner)
:
Component(owner),
layer(CollisionLayer::Default)
{}

C_Collider::~C_Collider() {}

const CollisionLayer C_Collider::GetLayer()
{
    return layer;
}

void C_Collider::SetLayer(CollisionLayer layer)
{
    // DAVID: I know I don't need to use `this` in this case, but
    // I think it looks more readible? The other way would be
    //
    //      `layer = layer`
    //
    // and I think that looks scuffed ...

    this->layer = layer;
}