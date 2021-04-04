#include "Components/KeyboardMovement.hpp"
#include "Engine/ECS/Object.hpp"

KeyboardMovement::KeyboardMovement(Object* owner) : Component(owner), moveSpeed(100) {}

void KeyboardMovement::SetInput(Input* input)
{
    // Ask Dave if this using this here is necessary ...
    this->input = input;
}

void KeyboardMovement::SetMovementSpeed(int moveSpeed)
{
    this->moveSpeed = moveSpeed;
}

void KeyboardMovement::Update(float deltaTime)
{
    if (input == nullptr)
    {
        return;
    }

    sf::Vector2f movement{0.f, 0.f};
    
    if (input->IsKeyPressed(Input::Key::Left))
    {
        movement.x = -moveSpeed;
    }
    else if (input->IsKeyPressed(Input::Key::Right))
    {
        movement.x = moveSpeed;
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