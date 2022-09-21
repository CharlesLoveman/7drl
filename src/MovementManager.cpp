#include "MovementManager.hpp"

#include "AttackEvent.hpp"
#include "Entity.hpp"
#include "Components.hpp"

bool MovementManager::handleEvent(MovementEvent &event) {
    Position &position = event.entity.get<Position>();
    std::optional<std::reference_wrapper<Entity>> blocker;
    if (!GameMap::getInstance().blocked(position.x + event.x, position.y + event.y, blocker)) {
        position.x += event.x;
        position.y += event.y;
    } else if (blocker) {
        AttackEvent attack = AttackEvent(event.entity, blocker->get());
        event.entity.raiseEvent(attack);
    }
    return true;
}

std::shared_ptr<MovementManager> MovementManager::instance;
std::shared_ptr<MovementManager> MovementManager::getInstance() {
    if (!instance) {
        instance = std::make_shared<MovementManager>();
    }
    return instance;
}