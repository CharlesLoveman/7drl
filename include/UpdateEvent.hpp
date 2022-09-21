#ifndef __UPDATEEVENT_H_
#define __UPDATEEVENT_H_

#include "Event.hpp"

class UpdateEvent : public Event {
public:
    UpdateEvent(Entity &e) : Event(e) {}
    virtual ~UpdateEvent() {}
    bool accept(Manager &m) override;
    ManagerID id() override;
};

#endif