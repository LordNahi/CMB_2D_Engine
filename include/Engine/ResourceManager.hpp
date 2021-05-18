#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <string>
#include <variant>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include <iostream>

#include "Animation.hpp"

// std::string - Key to texture ...
typedef std::pair<std::string, std::vector<FrameData>> Spritesheet;

class ResourceManager
{
    public:
        bool AddTexture(const std::string& key, const std::string& filePath);
        bool AddSpritesheet(const std::string& key, const std::string& filePath, int rowLength, int rowCount = 1, int frameMax = 0, float frameTime = 0.15f);
        bool HasTexture(const std::string& key);
        bool HasSpritesheet(const std::string& key);
        std::shared_ptr<sf::Texture> GetTexture(const std::string& key);
        std::shared_ptr<Spritesheet> GetSpritesheet(const std::string& key);

    private:
        std::unordered_map<std::string, std::shared_ptr<Spritesheet>> spritesheets;
        std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;

        template <typename T>
        bool HasResource(const std::unordered_map<std::string, std::shared_ptr<T>>& store, const std::string& key)
        {
            auto result = store.find(key);

            return result != store.end();
        }
};

#endif /* ResourceManager_hpp */