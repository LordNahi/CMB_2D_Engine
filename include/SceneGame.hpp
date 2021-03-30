#ifndef SceneGame_hpp
#define SceneGame_hpp

#include "Engine/Scene.hpp"
#include "Engine/Input.hpp"
#include "Engine/WorkingDirectory.hpp"

class SceneGame : public Scene
{
    public:
        SceneGame(WorkingDirectory& workingDir);

        void OnCreate() override;
        void OnDestroy() override;

        void ProcessInput() override;
        void Update(float deltaTime) override;
        void Draw(Window& window) override;

    private:
        WorkingDirectory workingDir;
        Input input;

        sf::Texture defaultTex;
        sf::Sprite defaultSprite;
};

#endif /* SceneGame_hpp */