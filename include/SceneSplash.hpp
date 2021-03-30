#ifndef SceneSplashScreen_hpp
#define SceneSplashScreen_hpp

#include <SFML/Graphics.hpp>

#include "Engine/SceneStateMachine.hpp"
#include "Engine/WorkingDirectory.hpp"

class SceneSplash : public Scene
{
    public:
        SceneSplash(
            WorkingDirectory& workingDir,
            SceneStateMachine& sceneStateMaching,
            Window& window);

        void OnCreate() override;
        void OnDestroy() override;
        void OnActivate() override;

        void SetSwitchToScene(unsigned int id);

        void Update(float deltaTime);
        void Draw(Window& window) override;

    private:
        sf::Texture splashTexture;
        sf::Sprite splashSprite;

        WorkingDirectory& workingDir;
        SceneStateMachine& sceneStateMachine;
        Window& window;

        float showForSeconds;

        float currentSeconds;

        unsigned int switchToState;
};

#endif /* SceneSplashScreen_hpp */