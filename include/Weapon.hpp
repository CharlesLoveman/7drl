#ifndef __WEAPON_H_
#define __WEAPON_H_

#include "Colour.hpp"
#include <libtcod.hpp>
#include <memory>
#include <string>
#include <vector>

class Crest;
class Entity;
class Weapon;

class Shots {
public:
    Shots(Entity &e, Weapon &w, int x, int y);
    ~Shots() {}
    void fire();
    Weapon &weapon;
    Entity &entity;
    float acc, crit, spread, range;
    int shots, numDice, diceSize, pen, target_x, target_y;
    static void initialise(tcod::Console *_console, tcod::Context *_context) {
        console = _console;
        context = _context;
        shotConsole = new tcod::Console{console->get_shape()};
    }
private:
    static tcod::Console *console;
    static tcod::Context *context;
    static tcod::Console *shotConsole;
};

class Entity;
class Weapon {
public:
    Weapon(std::string _name, float _acc, float _crit, float _spread, float _range, int _shots, int _numDice, int _diceSize, int _pen) : fg(Colour(1.0, 1.0, 1.0)), bg(Colour(0.0, 0.0, 0.0)) {
        name = _name;
        acc = _acc;
        crit = _crit;
        spread = _spread;
        range = _range;
        shots = _shots;
        numDice = _numDice;
        diceSize = _diceSize;
        pen = _pen;
        crests = std::vector<std::shared_ptr<Crest>>();
        ch = '-';
    }
    ~Weapon() {}
    std::unique_ptr<Shots> generate(Entity& entity, int x, int y);
    std::string describe();
    std::string verbose();
    std::string name;
    float acc, crit, spread, range;
    int shots, numDice, diceSize, pen;
    std::vector<std::shared_ptr<Crest>> crests;
    Colour fg;
    Colour bg;
    char ch;
};

#endif