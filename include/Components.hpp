#ifndef __COMPONENTS_H_
#define __COMPONENTS_H_

#include "Colour.hpp"
#include "Weapon.hpp"
#include <libtcod.hpp>
#include <vector>

enum class ComponentID {
    POSITION,
    TILE,
    FOV,
    STATS,
    WEAPONS,
};

struct Component {
    virtual ~Component() {};
};

struct Position : Component {
    Position(int _x, int _y, bool _blocks = true) : Component() {
        x = _x;
        y = _y;
        blocks = _blocks;
    }
    ~Position() {}
    int x, y;
    bool blocks;
    static ComponentID id() {return ComponentID::POSITION;}
};

struct Tile : Component {
    Tile(bool _walkable, bool _transparent, char _ch, Colour _fg, Colour _bg, Colour _dark_fg, Colour _dark_bg) : Component(), fg(_fg), bg(_bg), dark_fg(_dark_fg), dark_bg(_dark_bg) {
        walkable = _walkable;
        transparent = _transparent;
        ch = _ch;
    }
    ~Tile() {}
    static ComponentID id() {return ComponentID::TILE;}
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
    static ComponentID id() {return ComponentID::FOV;}
    int radius;
    bool light_walls;
    TCOD_fov_algorithm_t algo;
};

struct StatBlock : Component {
    StatBlock(int _hp, int _def) : Component() {
        hp = _hp;
        def = _def;
    }
    ~StatBlock() {}
    static ComponentID id() {return ComponentID::STATS;}
    int hp, def; 
};

struct Weapons : Component {
    Weapons() : Component() {}
    ~Weapons() {}
    static ComponentID id() {return ComponentID::WEAPONS;}
    std::vector<std::unique_ptr<Weapon>> weapons;
    Weapon& operator[](std::size_t idx) {return *weapons[idx];}
};

#endif