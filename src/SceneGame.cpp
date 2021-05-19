#include "SceneGame.hpp"
#include "Player.hpp"

using namespace Data::Player;

SceneGame::SceneGame(GameContext& game) : game(game) {}

void SceneGame::OnCreate()
{
    /**
     * DAVE: Is there som way we can create compound classes or
     * something along those lines? It'd be cool if I could create
     * my objects similar to...
     * 
     * auto player = Object<C_Sprite, C_Animation, C_Keyboard>();
     * 
     * player.FlipX()                (from C_Sprite)
     * player.AddAnimation(...)      (from C_Animation)
     * 
     * if (player.IsKeyPressed(...)) (from C_Keyboard)
     * 
     * Unsure if this is possible or even feasable but ask Dave ...
     */

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

    player->transform->SetX(300);
    player->transform->SetY(300);

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