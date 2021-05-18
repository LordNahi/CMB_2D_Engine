#ifndef SceneSplashScreen_hpp
#define SceneSplashScreen_hpp

#include <SFML/Graphics.hpp>

#include "GameContext.hpp"

class SceneSplash : public Scene
{
    public:
        SceneSplash(GameContext& game);

        void OnCreate() override;
        void OnDestroy() override;
        void OnActivate() override;

        void SetSwitchToScene(unsigned int id);

        void Update(float deltaTime);
        void Draw(Window& window) override;

    private:
        GameContext& game;

        sf::Sprite splashSprite;

        float showForSeconds = 5.f;
        float currentSeconds = 0.f;

        unsigned int switchToState;
};

#endif /* SceneSplashScreen_hpp */