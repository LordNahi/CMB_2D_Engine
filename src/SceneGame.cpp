#include "SceneGame.hpp"
#include "C_Sprite.hpp"
#include "C_KeyboardMovement.hpp"
#include "Object.hpp"

SceneGame::SceneGame(
    WorkingDirectory& workingDir,
    ResourceAllocator<sf::Texture>& textureAllocator)
    :
    workingDir(workingDir),
    textureAllocator(textureAllocator)
    {}

void SceneGame::OnCreate()
{
    auto player = std::make_shared<Object>();

    auto movement = player->AddComponent<C_KeyboardMovement>();
    movement->SetInput(&input);

    auto sprite = player->AddComponent<C_Sprite>();
    sprite->SetTextureAllocator(&textureAllocator);
    sprite->Load(workingDir.Get() + "default.png");

    objects.Add(player);
}

void SceneGame::OnDestroy() {}

void SceneGame::ProcessInput()
{
    input.Update();
}

void SceneGame::Update(float deltaTime)
{
    objects.ProcessRemovals();
    objects.ProcessNewObjects();

    objects.Update(deltaTime);
}

void SceneGame::LateUpdate(float deltaTime)
{
    objects.LateUpdate(deltaTime);
}

void SceneGame::Draw(Window& window)
{
    objects.Draw(window);
}