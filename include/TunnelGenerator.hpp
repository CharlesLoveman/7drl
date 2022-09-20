#ifndef TUNNELGEN_H_
#define TUNNELGEN_H_

#include <libtcod.hpp>
#include <vector>

class GameMap;

class TunnelGenerator {
public:
    virtual ~TunnelGenerator() {}
    virtual void generate(std::vector<TCODBsp*> rooms, GameMap *map) = 0;
};

#endif