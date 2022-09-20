#ifndef BASICROOMGENERATOR_H_
#define BASICROOMGENERATOR_H_

#include "RoomGenerator.hpp"
#include <libtcod.hpp>

class BasicRoomGenerator : public RoomGenerator {
public:
    BasicRoomGenerator();
    ~BasicRoomGenerator() {}
    Room generate(int x, int y, int width, int height, std::vector<Tile> *source, int source_width) override;
private:
    TCODRandom *rng;
};

#endif