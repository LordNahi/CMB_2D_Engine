#ifndef Sprite_hpp
#define Sprite_hpp

#include "Component.hpp"
#include "ResourceAllocator.hpp"

class Sprite : public Component
{
    public:
        Sprite(Object* owner);

        // Loads a sprite from file ...
        void Load(const std::string& filePath);
        void Load(int id);

        void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator);

        // Override Component's Draw method ...
        void Draw(Window& window) override;

        // We'll use this to update out sprite based on our position ...
        void LateUpdate(float deltaTime) override;

    private:
        ResourceAllocator<sf::Texture>* allocator;
        sf::Sprite sprite;
};

#endif /* Sprite_hpp */