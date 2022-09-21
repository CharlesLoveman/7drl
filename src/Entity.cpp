#include "Entity.hpp"

int Entity::nextId = 0;

int Entity::getId() {
    return id;
}

void Entity::raiseEvent(Event &e) {
    if (managers.contains(e.id())) {
        e.accept(*managers[e.id()]);
    }
}

void Entity::subscribe(std::shared_ptr<Manager> m) {
    managers.insert({m->id(), m});
}

Entity::Entity() {
    id = nextId++;
}

Entity::~Entity() {}