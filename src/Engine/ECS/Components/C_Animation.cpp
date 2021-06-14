#include "C_Animation.hpp"
#include "Object.hpp"

C_Animation::C_Animation(Object* owner) : Component(owner) {}

void C_Animation::Awake()
{
    c_sprite = owner->GetComponent<C_Sprite>();
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
    /**
     * NOTE: Important lesson learned here, it is unsafe to
     * call on dependent components without first null checking.
     * This is because every component an object may use will need
     * to have their `Awake` function ran to ensure components are
     * set up.
     */

    if (currentAnimation.second && c_sprite)
    {
        auto data = *currentAnimation.second->GetCurrentFrame();

        c_sprite->LoadTexture(data.key);
        c_sprite->SetTextureRect(data.x, data.y, data.width, data.height);
    }
}

int C_Animation::GetCurrentState()
{
    return currentAnimation.first;
}

sf::IntRect C_Animation::GetAnimationFrameRect()
{
    return {
        currentAnimation.second->GetCurrentFrame()->x,
        currentAnimation.second->GetCurrentFrame()->y,
        currentAnimation.second->GetCurrentFrame()->width,
        currentAnimation.second->GetCurrentFrame()->height
    };
}