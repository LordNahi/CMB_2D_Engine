#include "ResourceManager.hpp"

bool ResourceManager::AddTexture(const std::string& key, const std::string& filePath)
{
    if (HasTexture(key))
    {
        return true;
    }

    std::shared_ptr<sf::Texture> resource = std::make_shared<sf::Texture>();
    if (!resource->loadFromFile(filePath))
    {
        std::cout << "Failed to load Texture: " << filePath << std::endl;
        return false;
    }

    textures.insert(std::make_pair(key, resource));

    std::cout << "Successfully loaded Texture: " << filePath << std::endl;
    return true;
}

bool ResourceManager::AddSpritesheet(const std::string& key, const std::string& filePath, int rowLength, int rowCount, int frameMax, float frameTime)
{
    if (!AddTexture(key, filePath))
    {
        std::cout << "Failed to load Spritesheet." << std::endl;
        return false;
    }

    // We need data from the newly loaded texture ...
    sf::Texture& tex = *GetTexture(key);

    const auto tWidth  = tex.getSize().x;
    const auto tHeight = tex.getSize().y;
    const auto frameWidth  = tWidth / rowLength;
    const auto frameHeight = tHeight / rowCount; 

    std::vector<FrameData> frames;
    int frameIndex = 0;

    for (int row = 0; row < rowCount; row++)
    {
        for (int rowIndex = 0; rowIndex < rowLength; rowIndex++, frameIndex++)
        {
            FrameData frame;

            frame.key    = key;
            frame.x      = frameWidth * rowIndex;
            frame.y      = frameHeight * row;
            frame.width  = frameWidth;
            frame.height = frameHeight;
            frame.displayTimeSeconds = frameTime;

            frames.push_back(frame);
        }
    }

    const auto spritesheet = std::make_shared<Spritesheet>(key, frames);

    spritesheets.insert({ key, spritesheet });

    std::cout << "Successfully loaded Spritesheet: " << filePath << std::endl;
    std::cout << "Spritesheet Length: " << frameIndex << std::endl;

    return true;
}

bool ResourceManager::HasTexture(const std::string& key)
{
    return HasResource(textures, key);
}

bool ResourceManager::HasSpritesheet(const std::string& key)
{
    return HasResource(spritesheets, key);
}

std::shared_ptr<Spritesheet> ResourceManager::GetSpritesheet(const std::string& key)
{
    auto result = spritesheets.find(key);

    if (result != spritesheets.end())
    {
        return result->second;
    }

    return nullptr;
}

std::shared_ptr<sf::Texture> ResourceManager::GetTexture(const std::string& key)
{
    auto result = textures.find(key);

    if (result != textures.end())
    {
        return result->second;
    }

    return nullptr;
}