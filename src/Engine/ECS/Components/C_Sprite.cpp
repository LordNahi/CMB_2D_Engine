#include "C_Sprite.hpp"
#include "Object.hpp"

#include <iostream>

C_Sprite::C_Sprite(Object* owner) : Component(owner) { }

void C_Sprite::SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator)
{
    this->allocator = allocator;
}

void C_Sprite::Load(int id)
{
    std::cout << "Loading texture asset with ID: " << id << std::endl;

    if (id >= 0)
    {
        std::shared_ptr<sf::Texture> texture = allocator->Get(id);
        sprite.setTexture(*texture);
    }
}

void C_Sprite::Load(const std::string& filePath)
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

void C_Sprite::Draw(Window& window)
{
    window.Draw(sprite);
}

void C_Sprite::LateUpdate(float deltaTime)
{
    sprite.setPosition(owner->transform->GetPosition());
}