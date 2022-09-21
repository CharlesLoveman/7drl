#ifndef __RANDOMTUNNELGEN_H_
#define __RANDOMTUNNELGEN_H_

#include "TunnelGenerator.hpp"
#include <libtcod.hpp>

class RandomTunnelGenerator : public TunnelGenerator {
public:
    RandomTunnelGenerator();
    ~RandomTunnelGenerator() {}
    void generate(std::vector<Room> rooms, GameMap &map) override;
private:
    TCODRandom *rng;
};

#endif