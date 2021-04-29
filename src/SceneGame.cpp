#include "SceneGame.hpp"

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
    sprite->SetScale(5);
    sprite->SetOrigin(.4f);
    
    auto animation = player->AddComponent<C_Animation>();

    int vikingTextureId = textureAllocator.Add(workingDir.Get() + "viking.png");

    const int frameWidth = 40;
    const int frameHeight = 29;

    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>();
    std::shared_ptr<Animation> walkAnimation = std::make_shared<Animation>();

    // Idle Animation ...
    const float idleAnimFrameSeconds = 0.2f;

    idleAnimation->AddFrame(vikingTextureId, 120, 0,
                            frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureId, 160, 0,
                            frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureId, 0, 29,
                            frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureId, 40, 29,
                            frameWidth, frameHeight, idleAnimFrameSeconds);

    // Walk Animation ...
    const float walkAnimFrameSeconds = 0.15f;

    walkAnimation->AddFrame(vikingTextureId, 120, 58,
                            frameWidth, frameHeight, idleAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureId, 160, 58,
                            frameWidth, frameHeight, idleAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureId, 0, 87,
                            frameWidth, frameHeight, idleAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureId, 40, 87,
                            frameWidth, frameHeight, idleAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureId, 80, 87,
                            frameWidth, frameHeight, idleAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureId, 120, 87,
                            frameWidth, frameHeight, idleAnimFrameSeconds);

    animation->AddAnimation(AnimationState::Idle, idleAnimation);
    animation->AddAnimation(AnimationState::Walk, walkAnimation);

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