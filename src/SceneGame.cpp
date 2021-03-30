#include "SceneGame.hpp"
#include "Components/Sprite.hpp"
#include "Engine/ECS/Object.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir) : workingDir(workingDir)
{

}

void SceneGame::OnCreate()
{
    player = std::make_shared<Object>();

    // Here we add the sprite component to the player object ...
    // This will make our entity drawable/visible ...
    auto sprite = player->AddComponent<Sprite>();
    sprite->Load(workingDir.Get() + "default.png");
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

}

void SceneGame::Draw(Window& window)
{
    player->Draw(window);
}