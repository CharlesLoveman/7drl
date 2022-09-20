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
    bool hasComponent(int id);
    void raiseEvent(Event &e);
    void subscribe(Manager *m);
    void addComponent(int id, Component *component);
    template<typename T>
    T* get() {
        T *p = dynamic_cast<T*>(components[T::id()]);
        if (!p) throw std::runtime_error("Component did not match expected type!");
        return p;
    }
private:
    std::unordered_map<int, Component*> components;
    std::vector<Manager*> managers;
    int id;
    static int nextId;
};

#endif