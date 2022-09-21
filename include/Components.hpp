#ifndef __COMPONENTS_H_
#define __COMPONENTS_H_

#include "Colour.hpp"
#include <libtcod.hpp>

enum Components {
    POSITION,
    TILE,
    FOV,
};

struct Component {
    virtual ~Component() {};
};

struct Position : Component {
    Position(int _x, int _y) : Component() {
        x = _x;
        y = _y;
    }
    ~Position() {}
    int x, y;
    static int id() {return Components::POSITION;}
};

#include <cmath>



struct Tile : Component {
    Tile(bool _walkable, bool _transparent, char _ch, Colour _fg, Colour _bg, Colour _dark_fg, Colour _dark_bg) : Component() {
        walkable = _walkable;
        transparent = _transparent;
        ch = _ch;
        fg = _fg;
        bg = _bg;
        dark_fg = _dark_fg;
        dark_bg = _dark_bg;
    }
    ~Tile() {}
    static int id() {return Components::TILE;}
    bool walkable;
    bool transparent;
    char ch;
    Colour fg;
    Colour bg;
    Colour dark_fg;
    Colour dark_bg;
};

struct Fov : Component {
    Fov(int _radius, bool _light_walls=true, TCOD_fov_algorithm_t _algo=FOV_BASIC) {radius = _radius; light_walls = _light_walls; algo = _algo;}
    ~Fov() {}
    static int id() {return Components::FOV;}
    int radius;
    bool light_walls;
    TCOD_fov_algorithm_t algo;
};

#endif