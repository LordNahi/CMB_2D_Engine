#include "Game.hpp"

Game::Game() : window("mcflurry") { }

void Game::Update() {
    window.Update();
}

void Game::LateUpdate() { }

void Game::Draw() {
    window.BeginDraw();

    // We'll add draw code here ...

    window.EndDraw();
}

bool Game::IsRunning() const
{
    return window.IsOpen();
}