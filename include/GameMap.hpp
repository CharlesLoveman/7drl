#ifndef __GAMEMAP_H_
#define __GAMEMAP_H_

#include "Entity.hpp"
#include "Renderer.hpp"
#include <libtcod.hpp>
#include <vector>

struct Colour {
    uint8_t r, g, b;
    TCOD_ColorRGB toColor() {
        return TCOD_ColorRGB({r, g, b});
    }
};

struct Tile {
    bool walkable;
    bool transparent;
    char ch;
    Colour fg;
    Colour bg;
};


class GameMap : public Entity {
public:
    GameMap(int width, int height, Renderer *renderer);
    int width;
    int height;
    std::vector<Tile> tiles;   
    bool in_bounds(int x, int y);
    bool walkable(int x, int y);
private:
    Tile EmptyTile = {true, true, '.', {255, 255, 255}, {1, 1, 1}};
    Tile WallTile = {false, false, '#', {255, 255, 255}, {1, 1, 1}};
};

#endif