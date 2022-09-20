#ifndef BASICROOMGENERATOR_H_
#define BASICROOMGENERATOR_H_

#include "RoomGenerator.hpp"
#include <libtcod.hpp>

class BasicRoomGenerator : public RoomGenerator {
public:
    BasicRoomGenerator();
    ~BasicRoomGenerator() {}
    Room generate(int x, int y, int width, int height, GameMap *map) override;
private:
    TCODRandom *rng;
};

#endif