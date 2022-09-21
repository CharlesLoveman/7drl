#ifndef __ENTITYGEN_H_
#define __ENTITYGEN_H_

#include "Entity.hpp"
#include "RoomGenerator.hpp"
#include <memory>
#include <unordered_set>

class EntityGenerator {
public:
    virtual ~EntityGenerator() {}
    virtual void generate(Room&, GameMap&) = 0;
    bool randPos(Room&, GameMap&, Point&);
private:
    static constexpr int MAX_TRIES = 3;
};

#endif