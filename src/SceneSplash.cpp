#include "SceneSplash.hpp"

SceneSplash::SceneSplash(
    WorkingDirectory& workingDir,
    SceneStateMachine& sceneStateMachine,
    ResourceAllocator<sf::Texture>& textureAllocator,
    Window& window)
    :
    workingDir(workingDir),
    sceneStateMachine(sceneStateMachine),
    textureAllocator(textureAllocator),
    window(window),
    switchToState(0),
    currentSeconds(0.f),
    showForSeconds(1.f)
    {}

void SceneSplash::OnCreate()
{
    int textureID = textureAllocator.Add(workingDir.Get() + "splash.png");

    if (textureID >= 0)
    {
        splashSprite.setTexture(*textureAllocator.Get(textureID));

        sf::FloatRect spriteSize = splashSprite.getLocalBounds();

        splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
        
        sf::Vector2u windowCenter = window.GetCenter();

        splashSprite.setPosition(windowCenter.x, windowCenter.y);
    }
}

void SceneSplash::OnActivate()
{
    currentSeconds = 0.f;
}

void SceneSplash::OnDestroy() {}

void SceneSplash::SetSwitchToScene(unsigned int id)
{
    switchToState = id;
}

void SceneSplash::Update(float deltaTime)
{
    currentSeconds += deltaTime;

    if (currentSeconds >= showForSeconds)
    {
        sceneStateMachine.SwitchTo(switchToState);
    }
}

void SceneSplash::Draw(Window& window)
{
    window.Draw(splashSprite);
}