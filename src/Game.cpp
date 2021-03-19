#include <iostream>

#include "Game.hpp"

Game::Game() : window("mcflurry")
{
    defaultTex.loadFromFile(workingDir.Get() + "test.png");
    defaultSprite.setTexture(defaultTex);
    deltaTime = clock.restart().asSeconds();
}

void Game::Update() {
    std::cout << "dt: " << deltaTime << std::endl;

    window.Update();

    const int pps = 50;
    const float movement = pps * deltaTime;

    const auto& newPos = sf::Vector2f{
        defaultSprite.getPosition().x + movement,
        defaultSprite.getPosition().y
    };

    defaultSprite.setPosition(newPos.x, newPos.y);
}

void Game::LateUpdate() { }

void Game::Draw() {
    window.BeginDraw();

    window.Draw(defaultSprite);

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