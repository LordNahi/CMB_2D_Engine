#ifndef TileMapParser_hpp
#define TileMapParser_hpp

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <sstream>
#include <string.h>

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "Tile.hpp"
#include "Object.hpp"
#include "C_Sprite.hpp"

struct TileSheetData
{
    int columns;
    int rows;
    std::string textureId;
    sf::Vector2u imageSize;
    sf::Vector2u tileSize;
};

using namespace rapidxml;

typedef std::vector<std::shared_ptr<Tile>> Layer;
typedef std::map<std::string, std::shared_ptr<Layer>> TileMap; // Almost just prefer "Layers" as a name? ..
typedef std::unordered_map<unsigned int, std::shared_ptr<TileInfo>> TileSet;

class TileMapParser
{
    public:
        TileMapParser(GameContext& game);

        std::vector<std::shared_ptr<Object>> Parse(const std::string& file, sf::Vector2i offset);

    private:
        std::shared_ptr<TileSheetData> BuildTileSheetData(xml_node<>* rootNode);
        std::shared_ptr<TileMap> BuildTileMap(xml_node<>* rootNode);
        std::pair<std::string, std::shared_ptr<Layer>> BuildLayer(xml_node<>* layerNode, std::shared_ptr<TileSheetData> tileSheetData);

        GameContext& game;
};

#endif /* TileMapParser_hpp */