#ifndef KeyboardMovement_hpp
#define KeyboardMovement_hpp

#include "Component.hpp"
#include "Input.hpp"

#include "C_Animation.hpp"

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
};

#endif /* C_KeyboardMovement_hpp */