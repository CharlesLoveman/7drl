#ifndef TUNNELGEN_H_
#define TUNNELGEN_H_

#include "RoomGenerator.hpp"
#include <vector>

class GameMap;

class TunnelGenerator {
public:
    virtual ~TunnelGenerator() {}
    virtual void generate(std::vector<Room> rooms, GameMap &map) = 0;
};

#endif