#include "C_KeyboardMovement.hpp"
#include "Object.hpp"
#include "Player.hpp"

using namespace Data::Player;

C_KeyboardMovement::C_KeyboardMovement(Object* owner) : Component(owner) {}

void C_KeyboardMovement::Awake()
{
    c_sprite = owner->GetComponent<C_Sprite>();
}

void C_KeyboardMovement::SetMovementSpeed(int moveSpeed)
{
    moveSpeed = moveSpeed;
}

void C_KeyboardMovement::Update(float deltaTime)
{
    sf::Vector2f movement{0.f, 0.f};
    if (owner->game.input.IsKeyPressed(Input::Key::Left))
    {
        movement.x = -moveSpeed;

        if (c_sprite->GetScale().x > 0)
        {
            c_sprite->FlipX();
        }
    }
    else if (owner->game.input.IsKeyPressed(Input::Key::Right))
    {
        movement.x = moveSpeed;

        if (c_sprite->GetScale().x < 0)
        {
            c_sprite->FlipX();
        }
    }

    if (owner->game.input.IsKeyPressed(Input::Key::Up))
    {
        movement.y = -moveSpeed;
    }
    else if (owner->game.input.IsKeyPressed(Input::Key::Down))
    {
        movement.y = moveSpeed;
    }

    movement *= deltaTime;

    owner->transform->AddPosition(movement);
}