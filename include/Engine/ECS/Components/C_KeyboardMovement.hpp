#ifndef KeyboardMovement_hpp
#define KeyboardMovement_hpp

#include "Component.hpp"
#include "Input.hpp"

#include "C_Animation.hpp"
#include "C_Sprite.hpp"

class C_KeyboardMovement : public Component
{
    public:
        C_KeyboardMovement(Object* owner);

        void SetInput(Input* input);
        void SetMovementSpeed(int moveSpeed);

        void Awake() override;
        void Update(float deltaTime) override;

    private:
        int moveSpeed;
        Input* input;

        std::shared_ptr<C_Animation> c_animation;
        std::shared_ptr<C_Sprite> c_sprite;
};

#endif /* C_KeyboardMovement_hpp */