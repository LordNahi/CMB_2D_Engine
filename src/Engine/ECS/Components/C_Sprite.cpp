#include "C_Sprite.hpp"
#include "Object.hpp"

C_Sprite::C_Sprite(Object* owner) : Component(owner) { }

void C_Sprite::SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator)
{
    this->allocator = allocator;
}

void C_Sprite::Load(const std::string& key)
{
    if (allocator)
    {
        if (allocator->Has(key))
        {
            std::shared_ptr<sf::Texture> texture = allocator->Get(key);
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

void C_Sprite::SetScale(float scale)
{
    SetScale(scale, scale);
}

void C_Sprite::SetScale(float x, float y)
{
    sprite.setScale(x, y);
}

void C_Sprite::SetOrigin(float origin)
{
    SetOrigin(origin, origin);
}

void C_Sprite::SetOrigin(float x, float y)
{
    /** Storing the originNorm so when using `SetTextureRect()`
     * it can apply the origin to new texture rect ...
     */

    originNorm.x = x;
    originNorm.y = y;

    auto bounds = sprite.getLocalBounds();

    sprite.setOrigin({
        bounds.width * x,
        bounds.height * y
    });
}

sf::Vector2f C_Sprite::GetScale()
{
    return sprite.getScale();
}

sf::Vector2f C_Sprite::GetOrigin()
{
    return sprite.getOrigin();
}

void C_Sprite::FlipX()
{
    auto scale = GetScale();

    SetScale(-scale.x, scale.y);
}

void C_Sprite::FlipY()
{
    auto scale = GetScale();

    SetScale(scale.x, -scale.y);
}

void C_Sprite::SetTextureRect(int x, int y, int width, int height)
{
    sprite.setTextureRect(sf::IntRect(x, y, width, height));
    sprite.setOrigin(width * originNorm.x, height * originNorm.y);
}

void C_Sprite::SetTextureRect(const sf::IntRect& rect)
{
    sprite.setTextureRect(rect);
}