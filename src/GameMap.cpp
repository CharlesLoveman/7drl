#include "GameMap.hpp"

#include "MapRenderer.hpp"

GameMap::~GameMap() {
    delete map;
}

GameMap::GameMap(int _width, int _height, Renderer *renderer, RoomGenerator *_generator) : Entity() {
    width = _width;
    height = _height;
    map = new TCODMap(width, height);
    tiles = std::vector<Tile>(width * height, WallTile());
    seen = std::vector<bool>(width * height, false);
    subscribe(renderer);
    generator = _generator;
    generator->generate(1, 1, width - 2, height - 2, this);
}

bool GameMap::in_bounds(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool GameMap::walkable(int x, int y) {
    return in_bounds(x, y) && tiles[y * width + x].walkable;
}

void GameMap::set(int x, int y, const Tile &tile) {
    if (!in_bounds(x, y)) throw std::runtime_error("Tried to set tile not in bounds!");
    tiles[y * width + x] = tile;
    map->setProperties(x, y, tile.transparent, tile.walkable);
}