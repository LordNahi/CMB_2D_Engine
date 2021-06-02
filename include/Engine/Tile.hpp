#ifndef Tile_h
#define Tile_h

#include <SFML/Graphics.hpp>

struct TileInfo
{
    int tileId = -1;
    std::string textureId;
    sf::IntRect textureRect;
};

struct Tile
{
    int x;
    int y;
    std::shared_ptr<TileInfo> properties;
};

#endif /* Tile_h */