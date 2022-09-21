#ifndef __GAMEMAP_H_
#define __GAMEMAP_H_

#include "Entity.hpp"
#include "EntityGenerator.hpp"
#include "Renderer.hpp"
#include "RoomGenerator.hpp"
#include <libtcod.hpp>
#include <memory>
#include <unordered_set>
#include <vector>


class GameMap : public Entity {
public:
    GameMap(int width, int height, std::shared_ptr<Renderer> renderer);
    ~GameMap();
    int width;
    int height;
    std::vector<Tile> tiles;   
    std::vector<bool> seen;
    std::unique_ptr<TCODMap> map;
    std::unordered_set<std::unique_ptr<Entity>> entities;
    std::vector<Room> rooms;
    bool in_bounds(int x, int y);
    bool walkable(int x, int y);
    bool visible(int x, int y);
    bool blocked(int x, int y);
    void set(int x, int y, const Tile &tile);
    void generate(std::shared_ptr<RoomGenerator> room_generator, std::shared_ptr<EntityGenerator> entity_generator);
    static const Tile &EmptyTile() {
        static Tile empty_tile = Tile(true, true, '.', {0.4f, 0.4f, 0.4f}, {0.03, 0.04, 0.2}, {0.2, 0.2, 0.2}, {0.01, 0.02, 0.1});
        return empty_tile;
    }
    static const Tile &WallTile() {
        static Tile wall_tile = Tile(false, false, '#', {0.2, 0.2, 0.2}, {0.6, 0.6, 0.5}, {0.1, 0.1, 0.1}, {0.3, 0.3, 0.25});
        return wall_tile;
    }
    static const Tile &Shroud() {
        static Tile wall_tile = Tile(false, false, ' ', {0, 0, 0}, {0.01, 0.02, 0.1}, {0, 0, 0}, {0.01, 0.02, 0.1});
        return wall_tile;
    }
};

#endif