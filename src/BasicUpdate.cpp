#include "BasicUpdate.hpp"

#include "Entity.hpp"
#include "MovementEvent.hpp"
#include <libtcod.hpp>

bool BasicUpdate::handleEvent(UpdateEvent &event) {
    TCODRandom *rng = TCODRandom::getInstance();
    event.entity.raiseEvent<MovementEvent>(rng->get(-1,1), rng->get(-1,1));
    return true;
}

std::shared_ptr<BasicUpdate> BasicUpdate::instance;
std::shared_ptr<BasicUpdate> BasicUpdate::getInstance() {
    if (!instance) {
        instance = std::make_shared<BasicUpdate>();
    }
    return instance;
}