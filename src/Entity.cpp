#include "Entity.hpp"

int Entity::nextId = 0;

int Entity::getId() {
    return id;
}

std::vector<int> *Entity::get(int id) {
    return &components[id];
}

bool Entity::hasComponent(int id) {
    return components.contains(id);
}

void Entity::addComponent(int id, std::vector<int> component) {
    components.insert({id, component});
}

void Entity::raiseEvent(Event &e) {
    for (auto m : managers) {
        if (e.accept(*m)) return;
    }
    throw "Unhandled Event!";
}

void Entity::subscribe(Manager *m) {
    managers.push_back(m);
}

Entity::Entity() {
    id = nextId++;
}