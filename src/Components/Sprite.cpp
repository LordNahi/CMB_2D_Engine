#include "Components/Sprite.hpp"
#include "Engine/ECS/Object.hpp"

#include <iostream>

Sprite::Sprite(Object* owner) : Component(owner) { }

void Sprite::SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator)
{
    this->allocator = allocator;
}

void Sprite::Load(int id)
{
    std::cout << "Loading texture asset with ID: " << id << std::endl;

    if (id >= 0)
    {
        std::shared_ptr<sf::Texture> texture = allocator->Get(id);
        sprite.setTexture(*texture);
    }
}

void Sprite::Load(const std::string& filePath)
{
    if (allocator)
    {
        int textureID = allocator->Add(filePath);

        if (textureID >= 0)
        {
            std::shared_ptr<sf::Texture> texture = allocator->Get(textureID);
            sprite.setTexture(*texture);
        }
    }
}

void Sprite::Draw(Window& window)
{
    window.Draw(sprite);
}

void Sprite::LateUpdate(float deltaTime)
{
    sprite.setPosition(owner->transform->GetPosition());
}