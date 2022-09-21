#include "EntityGenerator.hpp"

#include "GameMap.hpp"

bool EntityGenerator::randPos(Room &room, Point &position) {
    GameMap &map = GameMap::getInstance();
    for (int i = 0; i < MAX_TRIES; ++i) {
        position = room.random(); 
        std::optional<std::reference_wrapper<Entity>> blocker;
        if (!map.blocked(position.x, position.y, blocker)) {
            return true;
        }
    }
    return false;
}