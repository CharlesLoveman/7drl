#include "BSPRoomGenerator.hpp"

#include "GameMap.hpp"
#include <libtcod.hpp>
#include <memory>
#include <unordered_set>

BSPRoomGenerator::BSPRoomGenerator(RoomGenerator *_generator, TunnelGenerator *_tunnel_generator, int _nb, int _minHSize, int _minVSize, float _maxHRatio, float _maxVRatio) : RoomGenerator() {
    rng = TCODRandom::getInstance();
    generator = _generator;
    tunnel_generator = _tunnel_generator;
    nb = _nb;
    minHSize = _minHSize;
    minVSize = _minVSize;
    maxHRatio = _maxHRatio;
    maxVRatio = _maxVRatio;
}

bool BSPRoomGenerator::GenCallback::visitNode(TCODBsp *node, void *userData) {
    GenData *data = (GenData *) userData;
    if (node->isLeaf()) {
        Room r = (data->generator)->generate(node->x, node->y, node->w, node->h, data->source, data->source_width);
        node->resize(r.x, r.y, r.width, r.height);
        data->leaves.push_back(node);
    } 
    return true;
}
    
Room BSPRoomGenerator::generate(int x, int y, int width, int height, std::vector<Tile> *source, int source_width) {
    TCODBsp bsp = TCODBsp(x, y, width, height);
    bsp.splitRecursive(rng, nb, minHSize, minVSize, maxHRatio, maxVRatio);
    GenData data = {source, source_width, generator, std::vector<TCODBsp*>()};
    bsp.traversePostOrder(new GenCallback(), &data);
    tunnel_generator->generate(data.leaves, source, source_width);
    return {x, y, width, height};
}