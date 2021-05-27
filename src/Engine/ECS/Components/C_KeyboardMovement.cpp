#include "C_KeyboardMovement.hpp"
#include "Object.hpp"
#include "Player.hpp"

using namespace Data::Player;

C_KeyboardMovement::C_KeyboardMovement(Object* owner) : Component(owner) {}

void C_KeyboardMovement::Awake()
{
    /**
     * NOTE: Currently have no real way of guaranteeing the component
     * recieves all necessary dependant components, should I be doing
     * something like `static_assert` or maybe just null checking?
     * Ideally if I can detect the components can't be retrieved then
     * I don't want the code to compile ...
     */

    c_sprite    = owner->GetComponent<C_Sprite>();
    c_animation = owner->GetComponent<C_Animation>();
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

    // Handle Animation State Management ...

    const auto isMoving    = movement.x != 0.f || movement.y != 0.f;
    const auto isAttacking = owner->game.input.IsKeyPressed(Input::Key::Attack);

    switch(c_animation->GetCurrentState())
    {
        case static_cast<int>(AnimationState::Idle):
            if (isMoving)
            {
                c_animation->SetAnimationState(AnimationState::Walk);
            }
            else
            {
                c_animation->SetAnimationState(AnimationState::Idle);
            }

            if (isAttacking)
            {
                c_animation->SetAnimationState(AnimationState::Attack);
            }
            break;

        case static_cast<int>(AnimationState::Walk):
            if (!isMoving)
            {
                c_animation->SetAnimationState(AnimationState::Idle);
            }
            break;

        case static_cast<int>(AnimationState::Attack):
            if (!isAttacking)
            {
                c_animation->SetAnimationState(AnimationState::Idle);
            }
            break;
    }

    owner->transform->AddPosition(movement);
}