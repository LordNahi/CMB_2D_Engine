#include "C_KeyboardMovement.hpp"
#include "Object.hpp"

C_KeyboardMovement::C_KeyboardMovement(Object* owner) : Component(owner), moveSpeed(100) {}

void C_KeyboardMovement::Awake()
{
    c_animation = owner->GetComponent<C_Animation>();
    c_sprite    = owner->GetComponent<C_Sprite>();
}

void C_KeyboardMovement::SetInput(Input* input)
{
    // Ask Dave if this using this here is necessary ...
    this->input = input;
}

void C_KeyboardMovement::SetMovementSpeed(int moveSpeed)
{
    this->moveSpeed = moveSpeed;
}

void C_KeyboardMovement::Update(float deltaTime)
{
    if (input == nullptr)
    {
        return;
    }

    sf::Vector2f movement{0.f, 0.f};
    
    if (input->IsKeyPressed(Input::Key::Left))
    {
        movement.x = -moveSpeed;

        if (c_sprite->GetScale().x > 0)
        {
            c_sprite->FlipX();
        }
    }
    else if (input->IsKeyPressed(Input::Key::Right))
    {
        movement.x = moveSpeed;

        if (c_sprite->GetScale().x < 0)
        {
            c_sprite->FlipX();
        }
    }

    // Set horizontal animation direction ...
    if (movement.x == 0.f && movement.y == 0.f)
    {
        c_animation->SetAnimationState(AnimationState::Idle);
    }
    else
    {
        c_animation->SetAnimationState(AnimationState::Walk);
    }

    if (input->IsKeyPressed(Input::Key::Up))
    {
        movement.y = -moveSpeed;
    }
    else if (input->IsKeyPressed(Input::Key::Down))
    {
        movement.y = moveSpeed;
    }

    movement *= deltaTime;

    owner->transform->AddPosition(movement);
}