#include <iostream>

#include "Engine/Game.hpp"

Game::Game() : window("mcflurry")
{
    auto sceneSplash = std::make_shared<SceneSplash>(workingDir, sceneStateMachine, textureAllocator, window);
    auto sceneGame = std::make_shared<SceneGame>(workingDir, textureAllocator);

    unsigned int sceneSplashID = sceneStateMachine.Add(sceneSplash);
    unsigned int sceneGameID = sceneStateMachine.Add(sceneGame);

    sceneSplash->SetSwitchToScene(sceneGameID);
    
    sceneStateMachine.SwitchTo(sceneSplashID);

    deltaTime = clock.restart().asSeconds();
}

void Game::ProcessInput()
{
    sceneStateMachine.ProcessInput();
}

void Game::Update() {
    window.Update();

    sceneStateMachine.Update(deltaTime);
}

void Game::LateUpdate() {
    sceneStateMachine.LateUpdate(deltaTime);
}

void Game::Draw() {
    window.BeginDraw();

    sceneStateMachine.Draw(window);

    window.EndDraw();
}

bool Game::IsRunning() const
{
    return window.IsOpen();
}

void Game::CalculateDeltaTime()
{
    deltaTime = clock.restart().asSeconds();
}