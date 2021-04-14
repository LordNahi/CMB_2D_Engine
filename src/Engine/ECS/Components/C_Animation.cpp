#include "C_Animation.hpp"
#include "Object.hpp"

C_Animation::C_Animation(Object* owner) : Component(owner), currentAnimation(AnimationState::None, nullptr)
{

}

void C_Animation::Awake()
{
    sprite = owner->GetComponent<C_Sprite>();
}

void C_Animation::Update(float deltaTime)
{
    if (currentAnimation.first != AnimationState::None)
    {
        bool newFrame = currentAnimation.second->UpdateFrame(deltaTime);

        if (newFrame)
        {
            // Is this the closest I can get to `FrameData&`? ...
            auto data = *currentAnimation.second->GetCurrentFrame();

            sprite->Load(data.id);
            sprite->SetTextureRect(data.x, data.y, data.width, data.height);
        }
    }
}

void C_Animation::AddAnimation(AnimationState state, std::shared_ptr<Animation> animation)
{
    auto inserted = animations.insert(std::make_pair(state, animation));

    if (currentAnimation.first == AnimationState::None)
    {
        SetAnimationState(state);
    }
}

void C_Animation::SetAnimationState(AnimationState state)
{
    // We only set an animation if it is not already
    // our current animation ...
    if (currentAnimation.first == state)
    {
        return;
    }

    auto animation = animations.find(state);
    if (animation != animations.end())
    {
        currentAnimation.first = animation->first;
        currentAnimation.second = animation->second;

        currentAnimation.second->Reset();
    }
}

const AnimationState& C_Animation::GetAnimationState() const
{
    // Returns our current animation state. We can use this
    // to compare the objects current state to a desired state.
    return currentAnimation.first;
}