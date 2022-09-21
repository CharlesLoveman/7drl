#include "MovementEvent.hpp"

#include "Manager.hpp"

bool MovementEvent::accept(Manager &m) {
    return m.handleEvent(*this);
}

ManagerID MovementEvent::id() {
    return ManagerID::MOVEMENT;
}