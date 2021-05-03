#ifndef ResourceAllocator_hpp
#define ResourceAllocator_hpp

#include <map>
#include <memory>
#include <string>
#include <iostream>

template <typename T>
class ResourceAllocator
{
    public:
        bool Add(std::string key, const std::string& filePath)
        {
            auto it = resources.find(key);
            if (it != resources.end())
            {
                std::cout << "Resource already exists: " << filePath << std::endl;
            }

            /**
             * NOTE: We're making the assumption any resource we
             * try to load will implement `loadFromFile`, SFML
             * resources do so we won't need to worry about this
             * for the most part ...
             */
            std::shared_ptr<T> resource = std::make_shared<T>();
            if (!resource->loadFromFile(filePath))
            {
                std::cout << "Failed to load resource: " << filePath << std::endl;
                return false;
            }

            resources.insert(
                std::make_pair(key, resource)
            );

            std::cout << "Successfully loaded resource: " << filePath << std::endl;
            return true;
        }

        void Remove(std::string key)
        {
            for (auto it = resources.begin(); it != resources.end(); ++it)
            {
                if (it->second.first == id)
                {
                    resources.erase(it->first);
                }
            }
        }

        std::shared_ptr<T> Get(std::string key)
        {
            for (auto it = resources.begin(); it != resources.end(); ++it)
            {
                if (it->first == key)
                {
                    // Return the resource ...
                    return it->second;
                }
            }

            return nullptr;
        }

        bool Has(std::string key)
        {
            return (Get(key) != nullptr);
        }

    private:
        std::map<std::string, std::shared_ptr<T>> resources;
};

#endif /* ResourceAllocator_hpp */