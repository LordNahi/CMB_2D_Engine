#include "Components/Sprite.hpp"

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