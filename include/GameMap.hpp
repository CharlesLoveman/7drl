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
    int width;
    int height;
    std::vector<Tile> tiles;   
    std::vector<bool> visible;
    std::vector<bool> seen;
    bool in_bounds(int x, int y);
    bool walkable(int x, int y);
    static const Tile &EmptyTile() {
        static Tile empty_tile = Tile(true, true, '.', {100, 100, 100}, {7, 11, 52});
        return empty_tile;
    }
    static const Tile &WallTile() {
        static Tile wall_tile = Tile(false, false, '#', {50, 50, 50}, {146, 142, 133});
        return wall_tile;
    }
private:
    RoomGenerator *generator;
};

#endif