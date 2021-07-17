#ifndef SceneGame_hpp
#define SceneGame_hpp

#include <memory>

#include "ObjectCollection.hpp"
#include "TileMapParser.hpp"
#include "GameContext.hpp"
#include "Input.hpp"
#include "Scene.hpp"
#include "Debug.hpp"
#include "Player.hpp"

#include "C_KeyboardMovement.hpp"
#include "C_Animation.hpp"
#include "C_Sprite.hpp"
#include "C_BoxCollider.hpp"

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
        ObjectCollection objects;
        TileMapParser mapParser;
        GameContext& game;
};

#endif /* SceneGame_hpp */