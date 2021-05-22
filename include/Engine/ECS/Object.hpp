#ifndef Object_hpp
#define Object_hpp

#include <type_traits>
#include <memory>
#include <vector>

#include "Window.hpp"
#include "Component.hpp"
#include "GameContext.hpp"
#include "C_Transform.hpp"

template <typename T>
concept ECSComponent = std::is_base_of<Component, T>::value;

class Object
{
    public:
        Object(GameContext& game);
        // Awake is called when object is created, used
        // to ensure required components are present ...
        void Awake();

        // Called after Awake() ...
        void Start();

        void Update(float deltaTime);
        void LateUpdate(float deltaTime);
        void Draw (Window& window);
        void Remove();
        bool GetIsRemoving();

        template <ECSComponent T> std::shared_ptr<T> AddComponent()
        {
            auto component = GetComponent<T>();

            if (component)
            {
                // Important, we can't have more than one of the same component
                // type in out component list ...
                return component;
            }
            else
            {
                // The object doesn't have this component so we create it and
                // add it to out components list ...
                std::shared_ptr<T> newComponent = std::make_shared<T>(this);
                components.push_back(newComponent);

                return newComponent;
            }
        }

        template <ECSComponent T> std::shared_ptr<T> GetComponent()
        {
            // Concept should take care of this now, but keeping as not 100% ...
            // static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

            /**
             * Guarantees we get the correct component back. Since we only
             * have a type parameter, while iterating through out components
             * we check if it can be dynamically cast to type T, our T is
             * constrained to an ECSComponent, if it successfully casts then
             * we know we've found the right component, finally return ...
             */
            for (auto& component : components)
            {
                if (std::dynamic_pointer_cast<T>(component))
                {
                    return std::dynamic_pointer_cast<T>(component);
                }
            }

            return nullptr;
        }

        /**
         * Required Components ...
         * 
         * NOTE: Typically in an ECS, the Entity class serves only as
         * an ID and a place to store/run components. An exception to
         * this rule is to consider what components might be used
         * commonly and adding them to your Entity base class and save
         * the headache of having to constantly add these components.
         * 
         * eg. we'll be making the transform component required as 
         * we probably want most things to have an x/y coordinate
         * and to be moveable/rotatable/scalable etc.
         */

        GameContext& game;
        std::shared_ptr<C_Transform> transform;

    private:
        std::vector<std::shared_ptr<Component>> components;
        bool isRemoving = false;
};

#endif /* Object_hpp */