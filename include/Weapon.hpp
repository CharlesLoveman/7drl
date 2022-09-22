#ifndef __WEAPON_H_
#define __WEAPON_H_

#include <memory>
#include <string>
#include <vector>

class Crest;
class Entity;
class Weapon;

class Shots {
public:
    Shots(Entity &e, const Weapon &w, int x, int y);
    ~Shots() {}
    void fire();
    const Weapon &weapon;
    Entity &entity;
    float acc, crit, spread, range;
    int shots, numDice, diceSize, pen, target_x, target_y;
};

class Entity;
class Weapon {
public:
    Weapon(std::string _name, float _acc, float _crit, float _spread, float _range, int _shots, int _numDice, int _diceSize, int _pen) {
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
    }
    ~Weapon() {}
    std::unique_ptr<Shots> generate(Entity& entity, int x, int y) const;
    std::string describe();
    std::string verbose();
    std::string name;
    float acc, crit, spread, range;
    int shots, numDice, diceSize, pen;
    std::vector<std::shared_ptr<Crest>> crests;
};

#endif