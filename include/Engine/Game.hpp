#ifndef Game_hpp
#define Game_hpp

#include "Input.hpp"
#include "GameContext.hpp"

// Game Scenes ...
#include "SceneSplash.hpp"
#include "SceneGame.hpp"

class Game
{
    public:
        Game();

        void ProcessInput();
        void Update();
        void LateUpdate();
        void Draw();
        void CalculateDeltaTime();
        bool IsRunning() const;

    private:
        GameContext game;

        sf::Clock clock;
        float deltaTime;
};

#endif /* Game_hpp */