#include <iostream>

#include "Game.hpp"

Game::Game()
{
    // auto sceneSplash = std::make_shared<SceneSplash>(game);
    auto sceneGame = std::make_shared<SceneGame>(game);

    // unsigned int sceneSplashID = game.sceneStateMachine.Add(sceneSplash);
    unsigned int sceneGameID = game.sceneStateMachine.Add(sceneGame);

    // sceneSplash->SetSwitchToScene(sceneGameID);
    
    game.sceneStateMachine.SwitchTo(sceneGameID);

    deltaTime = clock.restart().asSeconds();
}

void Game::ProcessInput()
{
    game.sceneStateMachine.ProcessInput();
}

void Game::Update() {
    game.window.Update();

    game.sceneStateMachine.Update(deltaTime);
}

void Game::LateUpdate() {
    game.sceneStateMachine.LateUpdate(deltaTime);
}

void Game::Draw() {
    game.window.BeginDraw();

    game.sceneStateMachine.Draw(game.window);

    game.window.EndDraw();
}

bool Game::IsRunning() const
{
    return game.window.IsOpen();
}

void Game::CalculateDeltaTime()
{
    deltaTime = clock.restart().asSeconds();
}