#include "SceneSplash.hpp"

SceneSplash::SceneSplash(
    WorkingDirectory& workingDir,
    SceneStateMachine& sceneStateMachine,
    Window& window) : workingDir(workingDir),
    sceneStateMachine(sceneStateMachine),
    window(window),
    switchToState(0),
    currentSeconds(0.f),
    showForSeconds(3.f)
    {}

void SceneSplash::OnCreate()
{
    splashTexture.loadFromFile(workingDir.Get() + "splash.png");
    splashSprite.setTexture(splashTexture);

    sf::FloatRect spriteSize = splashSprite.getLocalBounds();

    splashSprite.setOrigin(spriteSize.width * 0.5f,
                           spriteSize.height * 0.5f);
    
    splashSprite.setScale(2.f, 2.f);
    
    sf::Vector2u windowCenter = window.GetCenter();

    splashSprite.setPosition(windowCenter.x, windowCenter.y);
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