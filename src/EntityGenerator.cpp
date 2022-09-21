#include "EntityGenerator.hpp"

#include "GameMap.hpp"

bool EntityGenerator::randPos(Room &room, GameMap &map, Point &position) {
    for (int i = 0; i < MAX_TRIES; ++i) {
        position = room.random(); 
        if (!map.blocked(position.x, position.y)) {
            return true;
        }
    }
    return false;
}