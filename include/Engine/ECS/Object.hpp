#ifndef Object_hpp
#define Object_hpp

#include <memory>
#include <vector>

#include "Engine/ECS/Component.hpp"
#include "Engine/ECS/Transform.hpp"
#include "Engine/Window.hpp"


class Object
{
    public:
        Object();
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

        /**
         * Required Components ...
         * 
         * NOTE: Typically in an ECS, the Entity class serves only as
         * an ID and a place to store/run components. The tutorial
         * I was reading while buildint this made a point to say that
         * sometimes there are components that for you use case, you
         * might want all entities to possess.
         * 
         * eg. we'll be making the transform components required as 
         * we probably want most things to have an x/y coordinate,
         * and to be moveable.
         */

        std::shared_ptr<Transform> transform;

    private:
        std::vector<std::shared_ptr<Component>> components;
};

#endif /* Object_hpp */