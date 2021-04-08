#ifndef SceneGame_hpp
#define SceneGame_hpp

#include <memory>

#include "Engine/ObjectCollection.hpp"
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
        Input input;
        ObjectCollection objects;
        WorkingDirectory& workingDir;
        ResourceAllocator<sf::Texture>& textureAllocator;
};

#endif /* SceneGame_hpp */