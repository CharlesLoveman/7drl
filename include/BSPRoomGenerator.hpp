#ifndef BSPROOMGENERATOR_H_
#define BSPROOMGENERATOR_H_

#include "RoomGenerator.hpp"
#include <libtcod.hpp>

class BSPRoomGenerator : public RoomGenerator {
public:
    BSPRoomGenerator(RoomGenerator *generator, int _nb=4, int _minHSize=5, int _minVSize=5, float _maxHRatio=1.5f, float _maxVRatio=1.5f);
    ~BSPRoomGenerator() {}
    void generate(int x, int y, int width, int height, std::vector<Tile> *source, int source_width) override;
private:
    TCODRandom *rng;
    RoomGenerator *generator;
    int nb, minHSize, minVSize;
    float maxHRatio, maxVRatio;
    class GenCallback : public ITCODBspCallback {
    public:
        bool visitNode(TCODBsp *node, void *userData) {
            if (node->isLeaf()) {
                GenData *data = (GenData *) userData;
                (data->generator)->generate(node->x, node->y, node->w, node->h, data->source, data->source_width);
            }
            return true;
        }
    };
    struct GenData {
        std::vector<Tile> *source;
        int source_width;
        RoomGenerator *generator;
    }; 
};

#endif