#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "Input.hpp"

class Game
{
    public:
        Game();

        void Update();
        void LateUpdate();
        void Draw();
        bool IsRunning() const;
        void CalculateDeltaTime();
        void CaptureInput();

    private:
        Window window;
        WorkingDirectory workingDir;
        Input input;

        // Temp ...
        sf::Texture defaultTex;
        sf::Sprite defaultSprite;

        sf::Clock clock;
        float deltaTime;
};

#endif /* Game_hpp */