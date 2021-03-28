#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir) : workingDir(workingDir)
{

}

void SceneGame::OnCreate()
{
    defaultTex.loadFromFile(workingDir.Get() + "default.png");
    defaultSprite.setTexture(defaultTex);
}

void SceneGame::OnDestroy()
{

}

void SceneGame::ProcessInput()
{
    input.Update();
}

void SceneGame::Update(float deltaTime)
{
    const sf::Vector2f& spritePos = defaultSprite.getPosition();
    const int moveSpeed = 100;
    
    int xMove = 0;
    if(input.IsKeyPressed(Input::Key::Left))
    {
        xMove = -moveSpeed;
    }
    else if(input.IsKeyPressed(Input::Key::Right))
    {
        xMove = moveSpeed;
    }
    
    int yMove = 0;
    if(input.IsKeyPressed(Input::Key::Up))
    {
        yMove = -moveSpeed;
    }
    else if(input.IsKeyPressed(Input::Key::Down))
    {
        yMove = moveSpeed;
    }

    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;
    
    defaultSprite.setPosition(spritePos.x + xFrameMove, spritePos.y + yFrameMove);
}

void SceneGame::Draw(Window& window)
{
    window.Draw(defaultSprite);
}