#ifndef __DAMAGEEVENT_H_
#define __DAMAGEEVENT_H_

#include "Event.hpp"

class DamageEvent : public Event {
public:
    DamageEvent(Entity &e, int _damage) : Event(e) {
        damage = _damage;
    }
    ~DamageEvent() {}
    bool accept(Manager &m) override;
    ManagerID id() override;
    int damage;
};

#endif