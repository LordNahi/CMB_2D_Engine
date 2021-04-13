#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "Input.hpp"
#include "SceneStateMachine.hpp"
#include "ResourceAllocator.hpp"

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
        ResourceAllocator<sf::Texture> textureAllocator;

        sf::Clock clock;
        float deltaTime;

        SceneStateMachine sceneStateMachine;
};

#endif /* Game_hpp */