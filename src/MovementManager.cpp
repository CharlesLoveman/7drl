#include "MovementManager.hpp"

#include "Entity.hpp"
#include "Components.hpp"

bool MovementManager::handleEvent(MovementEvent &event) {
    Entity *e = event.entity;
    Position *position = e->get<Position>();
    if (map->walkable(position->x + event.x, position->y + event.y)) {
        position->x += event.x;
        position->y += event.y;
    }
    return true;
}