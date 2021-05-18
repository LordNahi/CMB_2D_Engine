#include "SceneSplash.hpp"

SceneSplash::SceneSplash(GameContext& game) : game(game) {}

void SceneSplash::OnCreate()
{

    auto didLoad = game.resourceManager.AddTexture("splash", game.workingDir.Get() + "splash.png");

    if (didLoad)
    {
        splashSprite.setTexture(*game.resourceManager.GetTexture("splash"));

        sf::FloatRect spriteSize = splashSprite.getLocalBounds();

        splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
        
        sf::Vector2u windowCenter = game.window.GetCenter();

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
        game.sceneStateMachine.SwitchTo(switchToState);
    }
}

void SceneSplash::Draw(Window& window)
{
    window.Draw(splashSprite);
}