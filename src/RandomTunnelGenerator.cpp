#include "RandomTunnelGenerator.hpp"

#include "GameMap.hpp"
#include <libtcod.hpp>
#include <memory>
#include <unordered_set>
#include <vector>

RandomTunnelGenerator::RandomTunnelGenerator() {
    rng = TCODRandom::getInstance();
}

void RandomTunnelGenerator::generate(std::vector<TCODBsp*> rooms, GameMap &map) {
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
            map.set(x, y, GameMap::EmptyTile());
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