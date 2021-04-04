#ifndef SceneGame_hpp
#define SceneGame_hpp

#include <memory>

#include "Engine/ResourceAllocator.hpp"
#include "Engine/Scene.hpp"
#include "Engine/Input.hpp"
#include "Engine/WorkingDirectory.hpp"
#include "Engine/ECS/Object.hpp"

class SceneGame : public Scene
{
    public:
        SceneGame(
            WorkingDirectory& workingDir,
            ResourceAllocator<sf::Texture>& textureAllocator);

        void OnCreate() override;
        void OnDestroy() override;

        void ProcessInput() override;
        void Update(float deltaTime) override;
        void LateUpdate(float deltaTime) override;
        void Draw(Window& window) override;

    private:
        WorkingDirectory& workingDir;
        ResourceAllocator<sf::Texture>& textureAllocator;
        Input input;

        std::shared_ptr<Object> player;
};

#endif /* SceneGame_hpp */