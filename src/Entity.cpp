#include "Entity.hpp"

int Entity::nextId = 0;

int Entity::getId() {
    return id;
}

Component *Entity::get(int id) {
    return components[id];
}

bool Entity::hasComponent(int id) {
    return components.contains(id);
}

void Entity::addComponent(int id, Component *component) {
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

Entity::~Entity() {
    for (auto i : components) {
        delete i.second;
    }
}