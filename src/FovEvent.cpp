#include "FovEvent.hpp"

#include "Manager.hpp"

bool FovEvent::accept(Manager &m) {
    return m.handleEvent(*this);
}

ManagerID FovEvent::id() {
    return ManagerID::FOV;
}