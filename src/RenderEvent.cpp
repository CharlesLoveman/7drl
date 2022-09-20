#include "RenderEvent.hpp"

#include "Manager.hpp"

bool RenderEvent::accept(Manager &m) {
    return m.handleEvent(*this);
}