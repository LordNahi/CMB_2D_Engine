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
        int Add(const std::string& filePath)
        {
            auto it = resources.find(filePath);
            if (it != resources.end())
            {
                return it->second.first;
            }

            /**
             * NOTE: We're makign the assumption any resource we
             * try to load will implement `loadFromFile`, SFML
             * resources do so we won't need to worry about this
             * for the most part ...
             */
            std::shared_ptr<T> resource = std::make_shared<T>();
            if (!resource->loadFromFile(filePath))
            {
                std::cout << "Failed to load resource: " << filePath << std::endl;
                return -1;
            }

            resources.insert(
                std::make_pair(filePath, std::make_pair(currentId, resource))
            );

            std::cout << "Successfully loaded resource: " << filePath << std::endl;

            return currentId++;
        }

        void Remove(int id)
        {
            for (auto it = resources.begin(); it != resources.end(); ++it)
            {
                if (it->second.first == id)
                {
                    resources.erase(it->first);
                }
            }
        }

        std::shared_ptr<T> Get(int id)
        {
            for (auto it = resources.begin(); it != resources.end(); ++it)
            {
                if (it->second.first == id)
                {
                    // Return the resource ...
                    return it->second.second;
                }
            }

            return nullptr;
        }

        bool Has(int id)
        {
            return (Get(id) != nullptr);
        }

    private:
        int currentId = 0;
        std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;
};

#endif /* ResourceAllocator_hpp */