#include "MovementManager.hpp"

#include "Entity.hpp"
#include "Components.hpp"

bool MovementManager::handleEvent(MovementEvent &event) {
    Position &position = event.entity.get<Position>();
    if (map.walkable(position.x + event.x, position.y + event.y)) {
        position.x += event.x;
        position.y += event.y;
    }
    return true;
}