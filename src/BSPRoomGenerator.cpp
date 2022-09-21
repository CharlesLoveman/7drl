#include "BSPRoomGenerator.hpp"

#include "GameMap.hpp"
#include <libtcod.hpp>
#include <memory>
#include <unordered_set>

BSPRoomGenerator::BSPRoomGenerator(std::shared_ptr<RoomGenerator> _generator, std::shared_ptr<TunnelGenerator> _tunnel_generator, int _nb, int _minHSize, int _minVSize, float _maxHRatio, float _maxVRatio) : RoomGenerator() {
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
    GenData *data = static_cast<GenData*>(userData);
    if (node->isLeaf()) {
        std::vector<Room> rooms = (data->generator).generate(node->x, node->y, node->w, node->h, data->map);
        data->leaves.insert(data->leaves.end(), rooms.begin(), rooms.end());
    } 
    return true;
}
    
std::vector<Room> BSPRoomGenerator::generate(int x, int y, int width, int height, GameMap &map) {
    TCODBsp bsp = TCODBsp(x, y, width, height);
    bsp.splitRecursive(rng, nb, minHSize, minVSize, maxHRatio, maxVRatio);
    GenData data = {map, *generator, std::vector<Room>()};
    bsp.traversePostOrder(new GenCallback(), &data);
    tunnel_generator->generate(data.leaves, map);
    return data.leaves;
}