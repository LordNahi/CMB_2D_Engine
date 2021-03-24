#include <iostream>

#include "Game.hpp"

Game::Game() : window("mcflurry")
{
    defaultTex.loadFromFile(workingDir.Get() + "test.png");
    defaultSprite.setTexture(defaultTex);
    deltaTime = clock.restart().asSeconds();
}

void Game::CaptureInput()
{
    input.Update();
}

void Game::Update() {
    window.Update();

    const int speed = 100;
    const float movement = speed * deltaTime;
    
    auto directionVec = sf::Vector2i{0, 0};

    if (input.IsKeyPressed(Input::Key::Up))
    {
        directionVec.y = -1;
    }

    if (input.IsKeyPressed(Input::Key::Down))
    {
        directionVec.y = 1;
    }

    if (input.IsKeyPressed(Input::Key::Left))
    {
        directionVec.x = -1;
    }

    if (input.IsKeyPressed(Input::Key::Right))
    {
        directionVec.x = 1;
    }

    const auto& updatedPos = sf::Vector2f{
        defaultSprite.getPosition().x + movement * directionVec.x,
        defaultSprite.getPosition().y + movement * directionVec.y
    };

    defaultSprite.setPosition(updatedPos.x, updatedPos.y);
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