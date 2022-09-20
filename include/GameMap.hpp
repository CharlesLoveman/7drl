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
        static Tile empty_tile = Tile(true, true, '.', {100, 100, 100}, {7, 11, 52}, {50, 50, 50}, {3, 5, 26});
        return empty_tile;
    }
    static const Tile &WallTile() {
        static Tile wall_tile = Tile(false, false, '#', {50, 50, 50}, {146, 142, 133}, {25, 25, 25}, {73, 71, 66});
        return wall_tile;
    }
    static const Tile &Shroud() {
        static Tile wall_tile = Tile(false, false, ' ', {1, 1, 1}, {3, 5, 26}, {1, 1, 1}, {3, 5, 26});
        return wall_tile;
    }
private:
    RoomGenerator *generator;
};

#endif