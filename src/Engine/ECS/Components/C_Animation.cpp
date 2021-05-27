#include "C_Animation.hpp"
#include "Object.hpp"

C_Animation::C_Animation(Object* owner) : Component(owner) {}

void C_Animation::Awake()
{
    sprite = owner->GetComponent<C_Sprite>();
}

void C_Animation::Update(float deltaTime)
{
    if (currentAnimation.second)
    {
        bool newFrame = currentAnimation.second->UpdateFrame(deltaTime);

        if (newFrame)
        {
            RefreshAnimationSprite();
        }
    }
}

void C_Animation::RefreshAnimationSprite()
{
    if (currentAnimation.second)
    {
        // Is this the closest I can get to `FrameData&`? ...
        auto data = *currentAnimation.second->GetCurrentFrame();

        sprite->LoadTexture(data.key);
        sprite->SetTextureRect(data.x, data.y, data.width, data.height);
    }

int C_Animation::GetCurrentState()
{
    return currentAnimation.first;
}