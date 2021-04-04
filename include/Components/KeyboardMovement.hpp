#ifndef KeyboardMovement_hpp
#define KeyboardMovement_hpp

#include "Engine/ECS/Component.hpp"
#include "Engine/Input.hpp"

class KeyboardMovement : public Component
{
    public:
        KeyboardMovement(Object* owner);

        void SetInput(Input* input);
        void SetMovementSpeed(int moveSpeed);

        void Update(float deltaTime) override;

    private:
        int moveSpeed;
        Input* input;
};

#endif /* KeyboardMovement_hpp */