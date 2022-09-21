#ifndef BSPROOMGENERATOR_H_
#define BSPROOMGENERATOR_H_

#include "RoomGenerator.hpp"
#include "TunnelGenerator.hpp"
#include <libtcod.hpp>
#include <memory>

class BSPRoomGenerator : public RoomGenerator {
public:
    BSPRoomGenerator(std::shared_ptr<RoomGenerator> generator, std::shared_ptr<TunnelGenerator> tunnel_generator, int _nb=4, int _minHSize=5, int _minVSize=5, float _maxHRatio=1.5f, float _maxVRatio=1.5f);
    ~BSPRoomGenerator() {}
    Room generate(int x, int y, int width, int height, GameMap &map) override;
private:
    TCODRandom *rng;
    std::shared_ptr<RoomGenerator> generator;
    std::shared_ptr<TunnelGenerator> tunnel_generator;
    int nb, minHSize, minVSize;
    float maxHRatio, maxVRatio;
    class GenCallback : public ITCODBspCallback {
    public:
        bool visitNode(TCODBsp *node, void *userData);
    };
    struct GenData {
        GameMap &map;
        RoomGenerator &generator;
        std::vector<TCODBsp*> leaves;
    };
     
};

#endif