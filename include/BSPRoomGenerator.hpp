#ifndef BSPROOMGENERATOR_H_
#define BSPROOMGENERATOR_H_

#include "RoomGenerator.hpp"
#include <libtcod.hpp>

class BSPRoomGenerator : public RoomGenerator {
public:
    BSPRoomGenerator(RoomGenerator *generator, int _nb=4, int _minHSize=5, int _minVSize=5, float _maxHRatio=1.5f, float _maxVRatio=1.5f);
    ~BSPRoomGenerator() {}
    Room generate(int x, int y, int width, int height, std::vector<Tile> *source, int source_width) override;
private:
    TCODRandom *rng;
    RoomGenerator *generator;
    int nb, minHSize, minVSize;
    float maxHRatio, maxVRatio;
    void generateTunnels(std::vector<TCODBsp *> rooms, std::vector<Tile> *source, int source_width);
    class GenCallback : public ITCODBspCallback {
    public:
        bool visitNode(TCODBsp *node, void *userData);
    };
    struct GenData {
        std::vector<Tile> *source;
        int source_width;
        RoomGenerator *generator;
        std::vector<TCODBsp*> leaves;
    };
     
};

#endif