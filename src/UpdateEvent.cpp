#include "UpdateEvent.hpp"

#include "Manager.hpp"

bool UpdateEvent::accept(Manager &m) {
    return m.handleEvent(*this);
}

ManagerID UpdateEvent::id() {
    return ManagerID::UPDATE;
}