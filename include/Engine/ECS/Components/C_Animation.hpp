#ifndef C_Animation_hpp
#define C_Animation_hpp

#include <type_traits>
#include <vector>

#include "Component.hpp"
#include "Animation.hpp"
#include "Object.hpp"
#include "C_Sprite.hpp"

template<typename T>
concept Enumerable = std::is_enum<T>::value;

class C_Animation : public Component
{
    public:
        C_Animation(Object* owner);

        void Awake() override;
        void Update(float deltaTime) override;

        template<Enumerable T>
        bool CreateAnimation(const std::string& key, std::vector<int> frames, T state)
        {
            const auto animation = std::make_shared<Animation>();

            // TODO: Why can I access private methods in `resourceManager` ...
            if (!owner->game.resourceManager.HasSpritesheet(key))
            {
                std::cout << "Failed to create animation. Couldn't find key: " << key << std::endl;
                return false;
            }

            const auto spritesheet = owner->game.resourceManager.GetSpritesheet(key);

            for (auto& frame : frames)
            {
                if (frame > spritesheet->second.size())
                {
                    std::cout << "Failed to create animation. Frame index out of bounds. " << std::endl;
                    return false;
                }

                animation->AddFrame(spritesheet->second[frame]);
            }

            std::cout << "Successfully added animation." << std::endl;
            std::cout << "Animation has " << animation->Size() << " frames." << std::endl;

            AddAnimation(state, animation);

            return true;
        }

        template<Enumerable T>
        void AddAnimation(const T& state, std::shared_ptr<Animation> animation)
        {
            animations.insert(std::make_pair(static_cast<int>(state), animation));

            if (!currentAnimation.second)
            {
                SetAnimationState(state);
            }
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