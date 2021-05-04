#ifndef C_Animation_hpp
#define C_Animation_hpp

#include <type_traits>

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

// TODO: Consider creating a concepts file ...
template<typename T>
concept Enumerable = std::is_enum<T>::value;

class C_Animation : public Component
{
    public:
        C_Animation(Object* owner);

        void Awake() override;
        void Update(float deltaTime) override;

        template<Enumerable T>
        void AddAnimation(T const& state, std::shared_ptr<Animation> animation)
        {
            // Originally checked if there was no active animation state
            // and would play this new state if not, unsure if I want to
            // commit to that ...

            animations.insert(std::make_pair(static_cast<int>(state), animation));
        }

        template<Enumerable T>
        void SetAnimationState(T const& state)
        {
            RefreshAnimationSprite();

            /**
             * DAVID: State is internally handled as an int, but we
             * type constrain public facing methods as enums, so
             * so we need to cast incoming state ...
             */
            auto stateCast = static_cast<int>(state);

            // We only set an animation if it is not already
            // our current animation ...
            if (currentAnimation.first == stateCast)
            {
                return;
            }

            auto animation = animations.find(stateCast);
            if (animation != animations.end())
            {
                currentAnimation.first = animation->first;
                currentAnimation.second = animation->second;

                currentAnimation.second->Reset();
            }
        }

        template<Enumerable T>
        bool IsCurrentState(T const& state)
        {
            return state == currentAnimation.first;
        }

        void RefreshAnimationSprite();

    private:
        // Required components ...
        std::shared_ptr<C_Sprite> sprite;

        std::map<int, std::shared_ptr<Animation>> animations;
        std::pair<int, std::shared_ptr<Animation>> currentAnimation = {-1, nullptr};
};

#endif /* C_Animation_hpp */