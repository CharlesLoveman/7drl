#ifndef __RANDOMTUNNELGEN_H_
#define __RANDOMTUNNELGEN_H_

#include "TunnelGenerator.hpp"

class RandomTunnelGenerator : public TunnelGenerator {
public:
    RandomTunnelGenerator();
    ~RandomTunnelGenerator() {}
    void generate(std::vector<TCODBsp*> rooms, std::vector<Tile> *source, int source_width) override;
private:
    TCODRandom *rng;
};

#endif