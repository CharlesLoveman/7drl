#include "BSPRoomGenerator.hpp"

#include "GameMap.hpp"
#include <libtcod.hpp>

BSPRoomGenerator::BSPRoomGenerator(RoomGenerator *_generator, int _nb, int _minHSize, int _minVSize, float _maxHRatio, float _maxVRatio) : RoomGenerator() {
    rng = TCODRandom::getInstance();
    generator = _generator;
    nb = _nb;
    minHSize = _minHSize;
    minVSize = _minVSize;
    maxHRatio = _maxHRatio;
    maxVRatio = _maxVRatio;
}

void BSPRoomGenerator::generate(int x, int y, int width, int height, std::vector<Tile> *source, int source_width) {
    TCODBsp bsp = TCODBsp(x, y, width, height);
    bsp.splitRecursive(rng, nb, minHSize, minVSize, maxHRatio, maxVRatio);
    GenData data = {source, source_width, generator};
    bsp.traversePostOrder(new GenCallback(), &data);
}