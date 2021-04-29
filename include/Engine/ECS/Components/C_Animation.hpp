#ifndef C_Animation_hpp
#define C_Animation_hpp

#include "Component.hpp"
#include "Animation.hpp"
#include "C_Sprite.hpp"

/**
 * TODO: For this component to be usable accross any sprite
 * there cannot be a generic state enum, this will likely
 * end up being being removed and functions like `AddAnimation`
 * will just take a string or int instead and leave it to the
 * user to decide how to manage their animation state ...
 * 
 * eg.
 * 
 * AddAnimation("somekey", animation) or
 * AddAnimation(0, animation)
 */
enum class AnimationState
{
    None,
    Idle,
    Walk
};

class C_Animation : public Component
{
    public:
        C_Animation(Object* owner);

        void Awake() override;
        void Update(float deltaTime) override;

        void AddAnimation(AnimationState state, std::shared_ptr<Animation> animation);
        void SetAnimationState(AnimationState state);
        void RefreshAnimationSprite();
        const AnimationState& GetAnimationState() const;

    private:
        // Required components ...
        std::shared_ptr<C_Sprite> sprite;

        std::map<AnimationState, std::shared_ptr<Animation>> animations;
        std::pair<AnimationState, std::shared_ptr<Animation>> currentAnimation;
};

#endif /* C_Animation_hpp */