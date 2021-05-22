#ifndef KeyboardMovement_hpp
#define KeyboardMovement_hpp

#include "Component.hpp"
#include "Input.hpp"

#include "C_Sprite.hpp"
#include "C_Animation.hpp"

class C_KeyboardMovement : public Component
{
    public:
        C_KeyboardMovement(Object* owner);

        void SetMovementSpeed(int moveSpeed);

        void Awake() override;
        void Update(float deltaTime) override;

    private:
        int moveSpeed = 100;

        std::shared_ptr<C_Sprite> c_sprite;
        std::shared_ptr<C_Animation> c_animation;
};

#endif /* C_KeyboardMovement_hpp */