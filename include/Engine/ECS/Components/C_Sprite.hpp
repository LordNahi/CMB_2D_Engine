#ifndef Sprite_hpp
#define Sprite_hpp

#include "Component.hpp"
#include "ResourceAllocator.hpp"

class C_Sprite : public Component
{
    public:
        C_Sprite(Object* owner);

        // Loads a sprite from file ...
        void Load(const std::string& filePath);
        void Load(int id);
        void FlipX();
        void FlipY();
        void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator);
        void SetTextureRect(int x, int y, int width, int height);
        void SetTextureRect(const sf::IntRect& rect);
        void SetScale(float scale);
        void SetScale(float x, float y);
        void SetOrigin(float origin);
        void SetOrigin(float x, float y);
        sf::Vector2f GetScale();
        sf::Vector2f GetOrigin();

        // Override Component's Draw method ...
        void Draw(Window& window) override;

        // We'll use this to update out sprite based on our position ...
        void LateUpdate(float deltaTime) override;

    private:
        ResourceAllocator<sf::Texture>* allocator;
        sf::Sprite sprite;

        int currentTextureID = -1;
        sf::Vector2f originNorm = {0.f, 0.f};

};

#endif /* C_Sprite */