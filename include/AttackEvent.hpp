#ifndef __ATTACKEVENT_H_
#define __ATTACKEVENT_H_

#include "Event.hpp"
#include <cstdlib>

class AttackEvent : public Event {
public:
    AttackEvent(Entity &self, int x, int y, std::size_t _weapon=0) : Event(self) {
        target_x = x;
        target_y = y;
        weapon = _weapon;
    }
    ~AttackEvent() {}
    bool accept(Manager &m) override;
    ManagerID id() override;
    int target_x, target_y;
    std::size_t weapon;
};

#endif