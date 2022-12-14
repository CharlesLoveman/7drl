#ifndef BASICROOMGENERATOR_H_
#define BASICROOMGENERATOR_H_

#include "RoomGenerator.hpp"
#include <libtcod.hpp>

class BasicRoomGenerator : public RoomGenerator {
public:
    BasicRoomGenerator();
    ~BasicRoomGenerator() {}
    std::vector<Room> generate(int x, int y, int width, int height) override;
private:
    TCODRandom *rng;
};

#endif