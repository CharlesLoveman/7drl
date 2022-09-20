#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Components.hpp"
#include "Event.hpp"
#include "Manager.hpp"
#include <unordered_map>
#include <vector>

class Entity {
public:
    Entity();
    ~Entity();
    int getId();
    Component *get(int id);
    bool hasComponent(int id);
    void raiseEvent(Event &e);
    void subscribe(Manager *m);
    void addComponent(int id, Component *component);
private:
    std::unordered_map<int, Component*> components;
    std::vector<Manager*> managers;
    int id;
    static int nextId;
};

#endif