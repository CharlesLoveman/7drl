#include "BSPRoomGenerator.hpp"

#include "GameMap.hpp"
#include <libtcod.hpp>
#include <memory>
#include <unordered_set>

BSPRoomGenerator::BSPRoomGenerator(RoomGenerator *_generator, int _nb, int _minHSize, int _minVSize, float _maxHRatio, float _maxVRatio) : RoomGenerator() {
    rng = TCODRandom::getInstance();
    generator = _generator;
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
    generateTunnels(data.leaves, source, source_width);
    return {x, y, width, height};
}

void BSPRoomGenerator::generateTunnels(std::vector<TCODBsp*> rooms, std::vector<Tile> *source, int source_width) {
    int n = rooms.size();
    auto sets = std::unordered_set<std::shared_ptr<std::unordered_set<int>>>();
    std::vector<std::shared_ptr<std::unordered_set<int>>> room_map = std::vector<std::shared_ptr<std::unordered_set<int>>>(n);
    for (int i = 0; i < n; ++i) {
        std::shared_ptr<std::unordered_set<int>> p = std::make_shared<std::unordered_set<int>>();
        p->insert(i);
        sets.insert(p);
        room_map[i] = p;
    }
    while (sets.size() > 1) {
        int a = rng->get(0, n - 1);
        int b = rng->get(0, n - 1);
        if (a == b) continue;
        TCODLine::init(rooms[a]->x + rooms[a]->w / 2, rooms[a]->y + rooms[a]->h / 2, rooms[b]->x + rooms[b]->w / 2, rooms[b]->y + rooms[b]->h / 2);
        int x, y;
        while (!TCODLine::step(&x, &y)) {
            (*source)[y * source_width + x] = GameMap::EmptyTile;
        }
        if (room_map[a] != room_map[b]) {
            std::vector<int> to_remove = std::vector<int>();
            for (auto i : *room_map[b]) {
                room_map[a]->insert(i);
                to_remove.push_back(i);
            }
            sets.extract(room_map[b]);
            for (auto i : to_remove) {
                room_map[i] = room_map[a];
            }
        }
    }
}