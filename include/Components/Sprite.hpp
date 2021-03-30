#ifndef Sprite_hpp
#define Sprite_hpp

#include "Engine/ECS/Component.hpp"

class Sprite : public Component
{
    public:
        Sprite(Object* owner);

        // Loads a sprite from file ...
        void Load(const std::string& filePath);

        // Override Component's Draw method ...
        void Draw(Window& window) override;

    private:
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif /* Sprite_hpp */