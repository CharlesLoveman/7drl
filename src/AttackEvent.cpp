#include "AttackEvent.hpp"

#include "Manager.hpp"

bool AttackEvent::accept(Manager &m) {
    return m.handleEvent(*this);
}

ManagerID AttackEvent::id() {
    return ManagerID::ATTACK;
}