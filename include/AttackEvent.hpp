#ifndef __ATTACKEVENT_H_
#define __ATTACKEVENT_H_

#include "Event.hpp"

class AttackEvent : public Event {
public:
    AttackEvent(Entity &self, Entity &other, int _weapon=0) : Event(self), target(other) {
        weapon = _weapon;
    }
    ~AttackEvent() {}
    bool accept(Manager &m) override;
    ManagerID id() override;
    Entity &target;
    int weapon;
};

#endif