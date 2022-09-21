#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Components.hpp"
#include "Event.hpp"
#include "Manager.hpp"
#include <memory>
#include <unordered_map>
#include <vector>

class Entity {
public:
    Entity();
    ~Entity();
    int getId();
    bool hasComponent(int id);
    void raiseEvent(Event &e);
    void subscribe(std::shared_ptr<Manager> m);

    template<typename T, typename... Args>
    void addComponent(Args... args) {
        components.insert({T::id(), std::make_unique<T>(args...)});
    }

    template<typename T>
    T& get() {
        return dynamic_cast<T&>(*components[T::id()]);
    }
private:
    std::unordered_map<int, std::unique_ptr<Component>> components;
    std::vector<std::shared_ptr<Manager>> managers;
    int id;
    static int nextId;
};

#endif