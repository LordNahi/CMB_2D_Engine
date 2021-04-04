#include "Components/Sprite.hpp"
#include "Engine/ECS/Object.hpp"

Sprite::Sprite(Object* owner) : Component(owner) { }

void Sprite::Load(const std::string& filePath)
{
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

void Sprite::Draw(Window& window)
{
    window.Draw(sprite);
}

void Sprite::LateUpdate(float deltaTime)
{
    sprite.setPosition(owner->transform->GetPosition());
}