#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "Input.hpp"
#include "SceneStateMachine.hpp"

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
        Window window;
        WorkingDirectory workingDir;

        sf::Clock clock;
        float deltaTime;

        SceneStateMachine sceneStateMachine;
};

#endif /* Game_hpp */