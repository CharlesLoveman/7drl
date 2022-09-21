#ifndef __GAMEMAP_H_
#define __GAMEMAP_H_

#include "Entity.hpp"
#include "Renderer.hpp"
#include "RoomGenerator.hpp"
#include <libtcod.hpp>
#include <vector>


class GameMap : public Entity {
public:
    GameMap(int width, int height, Renderer *renderer, RoomGenerator *generator);
    ~GameMap();
    int width;
    int height;
    std::vector<Tile> tiles;   
    std::vector<bool> seen;
    TCODMap *map;
    bool in_bounds(int x, int y);
    bool walkable(int x, int y);
    void set(int x, int y, const Tile &tile);
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
private:
    RoomGenerator *generator;
};

#endif