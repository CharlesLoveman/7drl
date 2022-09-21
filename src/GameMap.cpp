#include "GameMap.hpp"

#include "MapRenderer.hpp"

GameMap::~GameMap() {}

#include <iostream>
GameMap::GameMap(int _width, int _height, std::shared_ptr<Renderer> renderer, std::shared_ptr<RoomGenerator> _room_generator, std::shared_ptr<EntityGenerator> _entity_generator) : Entity() {
    width = _width;
    height = _height;
    map = std::make_unique<TCODMap>(width, height);
    tiles = std::vector<Tile>(width * height, WallTile());
    for (unsigned int i = 0; i < tiles.size(); ++i) {
        tiles[i].bg.shift(0.1f);
    }
    seen = std::vector<bool>(width * height, false);
    entities = std::unordered_set<std::unique_ptr<Entity>>();
    subscribe(renderer);
    room_generator = _room_generator;
    rooms = room_generator->generate(1, 1, width - 2, height - 2, *this);
    entity_generator = _entity_generator;
    for (auto r : rooms) {
        entity_generator->generate(r, entities);
    }
}

bool GameMap::in_bounds(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool GameMap::walkable(int x, int y) {
    return in_bounds(x, y) && tiles[y * width + x].walkable;
}

bool GameMap::visible(int x, int y) {
    return in_bounds(x, y) && map->isInFov(x, y);
}

void GameMap::set(int x, int y, const Tile &tile) {
    if (!in_bounds(x, y)) throw std::runtime_error("Tried to set tile not in bounds!");
    tiles[y * width + x] = tile;
    map->setProperties(x, y, tile.transparent, tile.walkable);
}