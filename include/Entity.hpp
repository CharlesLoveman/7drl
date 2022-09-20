#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Event.hpp"
#include "Manager.hpp"
#include <unordered_map>
#include <vector>

class Entity {
public:
    Entity();
    int getId();
    std::vector<int> *get(int id);
    bool hasComponent(int id);
    void raiseEvent(Event &e);
    void subscribe(Manager *m);
    void addComponent(int id, std::vector<int> component);
private:
    std::unordered_map<int, std::vector<int>> components;
    std::vector<Manager*> managers;
    int id;
    static int nextId;
};

#endif