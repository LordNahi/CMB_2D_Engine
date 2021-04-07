#include "SceneGame.hpp"
#include "Components/Sprite.hpp"
#include "Components/KeyboardMovement.hpp"
#include "Engine/ECS/Object.hpp"

SceneGame::SceneGame(
    WorkingDirectory& workingDir,
    ResourceAllocator<sf::Texture>& textureAllocator)
    :
    workingDir(workingDir),
    textureAllocator(textureAllocator)
    {}

void SceneGame::OnCreate()
{
    auto texId = textureAllocator.Add(workingDir.Get() + "default.png");

    player = std::make_shared<Object>();

    auto movement = player->AddComponent<KeyboardMovement>();
    movement->SetInput(&input);

    auto sprite = player->AddComponent<Sprite>();
    sprite->SetTextureAllocator(&textureAllocator);
    sprite->Load(texId);
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