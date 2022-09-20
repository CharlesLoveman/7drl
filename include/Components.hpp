#ifndef __COMPONENTS_H_
#define __COMPONENTS_H_

#include <libtcod.hpp>

enum Components {
    POSITION,
    TILE,
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
};

struct Colour {
    uint8_t r, g, b;
    TCOD_ColorRGB toColor() {
        return TCOD_ColorRGB({r, g, b});
    }
};

struct Tile : Component {
    Tile(bool _walkable, bool _transparent, char _ch, Colour _fg, Colour _bg) : Component() {
        walkable = _walkable;
        transparent = _transparent;
        ch = _ch;
        fg = _fg;
        bg = _bg;
    }
    ~Tile() {}
    bool walkable;
    bool transparent;
    char ch;
    Colour fg;
    Colour bg;
};

#endif