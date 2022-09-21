#include "EntityGenerator.hpp"

bool EntityGenerator::randPos(Room &room, std::unordered_set<std::unique_ptr<Entity>> &entities, Point &position) {
    for (int i = 0; i < MAX_TRIES; ++i) {
        position = room.random(); 
        bool empty = true;
        for (auto &&e : entities) {
            if (!e->hasComponent<Position>()) continue;
            Position &p = e->get<Position>();
            if (p.x == position.x && p.y == position.y) {
                empty = false;
                break;
            }
        }
        if (empty) {
            return true;
        }
    }
    return false;
}