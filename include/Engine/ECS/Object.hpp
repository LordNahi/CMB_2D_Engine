#ifndef Object_hpp
#define Object_hpp

#include <memory>
#include <vector>

#include "Engine/ECS/Component.hpp"
#include "Engine/Window.hpp"

class Object
{
    public:
        // Awake is called when object is created, used
        // to ensure required components are present ...
        void Awake();

        // Called after Awake() ...
        void Start();

        void Update(float deltaTime);
        void LateUpdate(float deltaTime);
        void Draw (Window& window);

        template <typename T> std::shared_ptr<T> AddComponent()
        {
            // This ensures that we only try to add a class that derives
            // from Component. This is tested at compile time.
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

            // Check we don't already have this component ...
            for (auto& component : components)
            {
                // Currently prevent the same component being added twice ...
                if (std::dynamic_pointer_cast<T>(component))
                {
                    return std::dynamic_pointer_cast<T>(component);
                }
            }

            // The object does nothave this component so we create it and
            // add it to out components list ...
            std::shared_ptr<T> newComponent = std::make_shared<T>(this);
            components.push_back(newComponent);

            return newComponent;
        }

        template <typename T> std::shared_ptr<T> GetComponent()
        {
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

            // Check if component exists in out 
            for (auto& component : components)
            {
                if (std::dynamic_pointer_cast<T>(component))
                {
                    return std::dynamic_pointer_cast<T>(component);
                }
            }

            return nullptr;
        }

    private:
        std::vector<std::shared_ptr<Component>> components;
};

#endif /* Object_hpp */