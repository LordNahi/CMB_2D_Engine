#include <ctime>

#include "TileMapParser.hpp"
#include "Utilities.hpp"

TileMapParser::TileMapParser(GameContext& game) : game(game) {}

std::vector<std::shared_ptr<Object>> TileMapParser::Parse(const std::string& file, sf::Vector2i offset)
{
    char* fileLoc = new char[file.size() + 1];

    #ifdef MACOS
        strlcpy(fileLoc, file.c_str(), file.size() + 1);
    #else
        strcpy_s(fileLoc, file.size() + 1, file.c_str());
    #endif


    // TODO: Verify file exists before trying to load it ...
    rapidxml::file<> xmlFile(fileLoc);
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    xml_node<>* rootNode = doc.first_node("map");

    // Loads tile laters from XML ...
    std::shared_ptr<TileMap> tileMap = BuildTileMap(rootNode);

    // We need these to calculate the tiles position in the world space ...
    int tileSizeX = std::atoi(rootNode->first_attribute("tilewidth")->value());
    int tileSizeY = std::atoi(rootNode->first_attribute("tileheight")->value());
    int mapSizeX  = std::atoi(rootNode->first_attribute("width")->value());
    int mapSizeY  = std::atoi(rootNode->first_attribute("height")->value());

    std::vector<std::shared_ptr<Object>> tileObjects;

    int layerCount = tileMap->size() - 1;

    for (const auto layer : *tileMap)
    {
        for (const auto tile : layer.second->tiles)
        {
            std::shared_ptr<TileInfo> tileInfo = tile->properties;
            std::shared_ptr<Object> tileObject = std::make_shared<Object>(game);

            // TODO: tile scale should be set at the data level ...
            const int tileScale = 3;

            if (layer.second->isVisible)
            {
                // Allocate sprite ...
                auto sprite = tileObject->AddComponent<C_Sprite>();

                sprite->LoadTexture(tileInfo->textureId);
                sprite->SetTextureRect(tileInfo->textureRect);
                sprite->SetScale(tileScale);
                sprite->SetSortOrder(layerCount);
            }

            // Calculate world position ...
            float x = tile->x * tileSizeX * tileScale + offset.x;
            float y = tile->y * tileSizeY * tileScale + offset.y;

            tileObject->transform->SetPosition(x, y);

            // NOTE: Tutorial didn't have this 
            if (layer.first == "Collisions" || "collisions")
            {
                auto collider = tileObject->AddComponent<C_BoxCollider>();
                
                float left   = x - (tileSizeX * tileScale) * 0.5f;
                float top    = y - (tileSizeY * tileScale) * 0.5f;
                float width  = tileSizeX * tileScale;
                float height = tileSizeY * tileScale;

                collider->SetCollidable({
                    left,
                    top,
                    width,
                    height
                });
                collider->SetLayer(CollisionLayer::Tile);
            }

            tileObjects.emplace_back(tileObject);
        }

        layerCount--;
    }

    // We called `new` so I assume we need to do this? ...
    delete fileLoc;

    return tileObjects;
}

std::shared_ptr<TileMap> TileMapParser::BuildTileMap(xml_node<>* rootNode)
{
    std::shared_ptr<TileSheets> tileSheetData = BuildTileSheetData(rootNode);

    std::shared_ptr<TileMap> map = std::make_shared<TileMap>();

    // Loop through each layer in the XML document ...
    for (xml_node<>* node = rootNode->first_node("layer"); node; node = node->next_sibling())
    {
        std::pair<std::string, std::shared_ptr<Layer>> mapLayer = BuildLayer(node, tileSheetData);

        map->emplace(mapLayer);
    }

    return map;
}

std::shared_ptr<TileSheets> TileMapParser::BuildTileSheetData(xml_node<>* rootNode)
{
    TileSheets tileSheets;

    for (xml_node<>* tileSheetNode = rootNode->first_node("tileset"); tileSheetNode; tileSheetNode = tileSheetNode->next_sibling("tileset"))
    {
        TileSheetData tileSheetData;

        // Id of the tilesheet ...
        int firstId = std::atoi(tileSheetNode->first_attribute("firstgid")->value());

        // Build the tile set data ...
        tileSheetData.tileSize.x = std::atoi(tileSheetNode->first_attribute("tilewidth")->value());
        tileSheetData.tileSize.y = std::atoi(tileSheetNode->first_attribute("tileheight")->value());
        
        int tileCount = std::atoi(tileSheetNode->first_attribute("tilecount")->value());

        tileSheetData.columns = std::atoi(tileSheetNode->first_attribute("columns")->value());
        tileSheetData.rows = tileCount / tileSheetData.columns;

        xml_node<>* imageNode = tileSheetNode->first_node("image");

        // I needed a unique-ish textureId leave me alone ...
        tileSheetData.textureId = "tex_" + std::to_string(std::time(nullptr));
        
        // TODO: add error checking - we want to output a message if a texture is not found ...
        const std::string filePath = game.workingDir.Get() + std::string(imageNode->first_attribute("source")->value());
        game.resourceManager.AddTexture(tileSheetData.textureId, filePath);

        tileSheetData.imageSize.x = std::atoi(imageNode->first_attribute("width")->value());
        tileSheetData.imageSize.y = std::atoi(imageNode->first_attribute("height")->value());

        tileSheets.insert(std::make_pair(firstId, std::make_shared<TileSheetData>(tileSheetData)));
    }
    
    return std::make_shared<TileSheets>(tileSheets);
}

std::pair<std::string, std::shared_ptr<Layer>> TileMapParser::BuildLayer(xml_node<>* layerNode, std::shared_ptr<TileSheets> tileSheets)
{
    TileSet tileSet;
    std::shared_ptr<Layer> layer = std::make_shared<Layer>();

    int width = std::atoi(layerNode->first_attribute("width")->value());
    int height = std::atoi(layerNode->first_attribute("height")->value());

    xml_node<>* dataNode = layerNode->first_node("data");
    char* mapIndices = dataNode->value();

    std::stringstream fileStream(mapIndices);

    int count = 0;

    std::string line;
    while(fileStream.good())
    {
        std::string substr;
        std::getline(fileStream, substr, ',');

        if (!Utilities::IsInteger(substr))
        {
            // We remove special characters from the in before parsing ...
            substr.erase(std::remove(substr.begin(), substr.end(), '\r'));
            substr.erase(std::remove(substr.begin(), substr.end(), '\n'));

            // TODO: add additional check to confirm the character removal worked ...
        }

        int tileId = std::stoi(substr);

        if (tileId != 0)
        {
            auto itr = tileSet.find(tileId);
            if (itr == tileSet.end())
            {
                std::shared_ptr<TileSheetData> tileSheetData;

                for (auto iter = tileSheets->rbegin(); iter != tileSheets->rend(); ++iter)
                {
                    if (tileId >= iter->first)
                    {
                        tileSheetData = iter->second;
                        break;
                    }
                }

                if (!tileSheetData)
                {
                    // TODO: Output error message ...
                    continue;
                }

                int textureX = tileId % tileSheetData->columns - 1;
                int textureY = tileId / tileSheetData->columns;

                std::shared_ptr<TileInfo> tileInfo = 
                    std::make_shared<TileInfo>(
                        tileId,
                        tileSheetData->textureId,
                        sf::IntRect(
                            textureX * tileSheetData->tileSize.x,
                            textureY * tileSheetData->tileSize.y,
                            tileSheetData->tileSize.x,
                            tileSheetData->tileSize.y
                        )
                    );

                itr = tileSet.insert(std::make_pair(tileId, tileInfo)).first;
            }

            std::shared_ptr<Tile> tile = std::make_shared<Tile>();

            // Bind properties of a tile from a set ...
            tile->properties = itr->second;
            tile->x = count % width - 1;
            tile->y = count / width;

            layer->tiles.emplace_back(tile);
        }

        count ++;
    }

    const std::string layerName = layerNode->first_attribute("name")->value();

    bool layerVisible = true;
    xml_attribute<>* visibleAttribute = layerNode->first_attribute("visible");
    if (visibleAttribute)
    {
        layerVisible = static_cast<bool>(std::atoi(visibleAttribute->value()));
    }
    layer->isVisible = layerVisible;

    return std::make_pair(layerName, layer);
}