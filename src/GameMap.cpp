#include "GameMap.hpp"

#include "MapRenderer.hpp"

GameMap::~GameMap() {}

#include <iostream>
GameMap::GameMap(int _width, int _height, std::shared_ptr<Renderer> renderer) : Entity() {
    width = _width;
    height = _height;
    map = std::make_unique<TCODMap>(width, height);
    subscribe(renderer);
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

bool GameMap::blocked(int x, int y) {
    if (!walkable(x, y)) 
        return true;
    for (auto &&e : entities) {
        if (!e->hasComponent<Position>()) continue;
        Position &p = e->get<Position>();
        if (!p.blocks) continue;
        if (p.x == x && p.y == y)
            return true;
    } 
    return false;
}

void GameMap::set(int x, int y, const Tile &tile) {
    if (!in_bounds(x, y)) throw std::runtime_error("Tried to set tile not in bounds!");
    tiles[y * width + x] = tile;
    map->setProperties(x, y, tile.transparent, tile.walkable);
}

void GameMap::generate(std::shared_ptr<RoomGenerator> room_generator, std::shared_ptr<EntityGenerator> entity_generator) {
    tiles = std::vector<Tile>(width * height, WallTile());
    for (unsigned int i = 0; i < tiles.size(); ++i) {
        tiles[i].bg.shift(0.1f);
    }
    seen = std::vector<bool>(width * height, false);
    entities = std::unordered_set<std::unique_ptr<Entity>>();
    rooms = room_generator->generate(1, 1, width - 2, height - 2, *this);
    for (auto r : rooms) {
        entity_generator->generate(r, *this);
    }
}