#ifndef __ATTACKEVENT_H_
#define __ATTACKEVENT_H_

#include "Event.hpp"

class AttackEvent : public Event {
public:
    AttackEvent(Entity &self, Entity &other) : Event(self), target(other) {}
    ~AttackEvent() {}
    bool accept(Manager &m) override;
    ManagerID id() override;
    Entity &target;
};

#endif