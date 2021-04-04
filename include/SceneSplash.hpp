#ifndef SceneSplashScreen_hpp
#define SceneSplashScreen_hpp

#include <SFML/Graphics.hpp>

#include "Engine/ResourceAllocator.hpp"
#include "Engine/SceneStateMachine.hpp"
#include "Engine/WorkingDirectory.hpp"

class SceneSplash : public Scene
{
    public:
        SceneSplash(
            WorkingDirectory& workingDir,
            SceneStateMachine& sceneStateMaching,
            ResourceAllocator<sf::Texture>& textureAllocator,
            Window& window);

        void OnCreate() override;
        void OnDestroy() override;
        void OnActivate() override;

        void SetSwitchToScene(unsigned int id);

        void Update(float deltaTime);
        void Draw(Window& window) override;

    private:
        WorkingDirectory& workingDir;
        SceneStateMachine& sceneStateMachine;
        ResourceAllocator<sf::Texture>& textureAllocator;
        Window& window;

        sf::Sprite splashSprite;

        float showForSeconds;
        float currentSeconds;

        unsigned int switchToState;
};

#endif /* SceneSplashScreen_hpp */