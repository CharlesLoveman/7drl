#include "MovementManager.hpp"

#include "Entity.hpp"
#include "Components.hpp"

bool MovementManager::handleEvent(MovementEvent &event) {
    Entity *e = event.entity;
    Component *c = e->get(Components::POSITION);
    Position *position = dynamic_cast<Position*>(c);
    if (!position) throw std::runtime_error("Position Component was not a Position!");
    if (map->walkable(position->x + event.x, position->y + event.y)) {
        position->x += event.x;
        position->y += event.y;
    }
    return true;
}