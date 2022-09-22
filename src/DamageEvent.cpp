#include "DamageEvent.hpp"

#include "Manager.hpp"

bool DamageEvent::accept(Manager &m) {
    return m.handleEvent(*this);
}

ManagerID DamageEvent::id() {
    return ManagerID::DAMAGE;
}