#include "SceneGame.hpp"
#include "Player.hpp"

using namespace Data::Player;

SceneGame::SceneGame(GameContext& game) : game(game), mapParser(game) {}

void SceneGame::OnCreate()
{
    game.resourceManager.AddTexture("viking", game.workingDir.Get() + "viking.png");
    game.resourceManager.AddSpritesheet("viking", game.workingDir.Get() + "viking.png", 5, 4);

    auto player = std::make_shared<Object>(game);

    auto movement = player->AddComponent<C_KeyboardMovement>();

    auto sprite = player->AddComponent<C_Sprite>();
    sprite->SetScale(5);
    sprite->SetOrigin(.4f);
    
    auto animation = player->AddComponent<C_Animation>();
    animation->CreateAnimation("viking", {3, 4, 5, 6}, AnimationState::Idle);
    animation->CreateAnimation("viking", {13, 14, 15, 16, 17, 18}, AnimationState::Walk);
    animation->CreateAnimation("viking", {1, 0}, AnimationState::Attack);

    player->transform->SetX(300);
    player->transform->SetY(300);

    // Level Creation Stuff ...
    sf::Vector2i mapOffset(50, -150);
    std::vector<std::shared_ptr<Object>> levelTiles
        = mapParser.Parse(game.workingDir.Get() + "tilemap_1.tmx", mapOffset);

    // Add in render order ...
    objects.Add(levelTiles);
    objects.Add(player);
}

void SceneGame::OnDestroy() {}

void SceneGame::ProcessInput()
{
    game.input.Update();
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