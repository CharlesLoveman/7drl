#include "MovementManager.hpp"

#include "Entity.hpp"
#include "Components.hpp"

bool MovementManager::handleEvent(MovementEvent &event) {
    Entity *e = event.entity;
    auto position = e->get(Component::POSITION);
    if (map->walkable((*position)[0] + event.x, (*position)[1] + event.y)) {
        (*position)[0] += event.x;
        (*position)[1] += event.y;
    }
    return true;
}