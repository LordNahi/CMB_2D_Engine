#ifndef SceneGame_hpp
#define SceneGame_hpp

#include <memory>

#include "ObjectCollection.hpp"
#include "GameContext.hpp"
#include "Input.hpp"
#include "Scene.hpp"

#include "C_Animation.hpp"
#include "C_Sprite.hpp"
#include "C_KeyboardMovement.hpp"

class SceneGame : public Scene
{
    public:
        SceneGame(GameContext& game);

        void OnCreate() override;
        void OnDestroy() override;

        void ProcessInput() override;
        void Update(float deltaTime) override;
        void LateUpdate(float deltaTime) override;
        void Draw(Window& window) override;

    private:
        GameContext& game;
        ObjectCollection objects;
};

#endif /* SceneGame_hpp */