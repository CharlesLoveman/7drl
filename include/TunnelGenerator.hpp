#ifndef TUNNELGEN_H_
#define TUNNELGEN_H_

#include <libtcod.hpp>
#include <vector>

struct Tile;

class TunnelGenerator {
public:
    virtual ~TunnelGenerator() {}
    virtual void generate(std::vector<TCODBsp*> rooms, std::vector<Tile> *source, int source_width) = 0;
};

#endif