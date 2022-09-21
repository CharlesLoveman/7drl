#include "Entity.hpp"

int Entity::nextId = 0;

int Entity::getId() {
    return id;
}

bool Entity::hasComponent(int id) {
    return components.contains(id);
}

void Entity::raiseEvent(Event &e) {
    for (auto m : managers) {
        if (e.accept(*m)) return;
    }
    throw "Unhandled Event!";
}

void Entity::subscribe(std::shared_ptr<Manager> m) {
    managers.push_back(m);
}

Entity::Entity() {
    id = nextId++;
}

Entity::~Entity() {}