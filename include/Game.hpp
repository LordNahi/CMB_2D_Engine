#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
#include "WorkingDirectory.hpp"

class Game
{
    public:
        Game();

        void Update();
        void LateUpdate();
        void Draw();
        bool IsRunning() const;
        void CalculateDeltaTime();

    private:
        Window window;
        WorkingDirectory workingDir;

        // Temp ...
        sf::Texture defaultTex;
        sf::Sprite defaultSprite;

        sf::Clock clock;
        float deltaTime;
};

#endif /* Game_hpp */