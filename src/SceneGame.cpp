#include "SceneGame.hpp"
#include "Components/Sprite.hpp"
#include "Components/KeyboardMovement.hpp"
#include "Engine/ECS/Object.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir) : workingDir(workingDir) {}

void SceneGame::OnCreate()
{
    player = std::make_shared<Object>();

    auto movement = player->AddComponent<KeyboardMovement>();
    auto sprite   = player->AddComponent<Sprite>();

    movement->SetInput(&input);
    sprite->Load(workingDir.Get() + "default.png");
}

void SceneGame::OnDestroy() {}

void SceneGame::ProcessInput()
{
    input.Update();
}

void SceneGame::Update(float deltaTime)
{
    player->Update(deltaTime);
}

void SceneGame::LateUpdate(float deltaTime)
{
    player->LateUpdate(deltaTime);
}

void SceneGame::Draw(Window& window)
{
    player->Draw(window);
}