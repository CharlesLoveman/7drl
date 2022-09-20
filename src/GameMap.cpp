#include "GameMap.hpp"

#include "MapRenderer.hpp"

GameMap::GameMap(int _width, int _height, Renderer *renderer, RoomGenerator *_generator) : Entity() {
    width = _width;
    height = _height;
    for (int i = 0; i < width * height; ++i) {
        tiles.push_back(EmptyTile);
    }
    subscribe(renderer);
    generator = _generator;
    generator->generate(1, 1, width - 1, height - 1, &tiles, width);
}

bool GameMap::in_bounds(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool GameMap::walkable(int x, int y) {
    return in_bounds(x, y) && tiles[y * width + x].walkable;
}