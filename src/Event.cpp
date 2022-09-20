#include "Event.hpp"

#include "Manager.hpp"

Event::Event(Entity *e) {
    entity = e;
}

Event::~Event() {}