#ifndef __FOVEVENT_H_
#define __FOVEVENT_H_

#include "Event.hpp"

class FovEvent : public Event {
public:
    FovEvent(Entity *e) : Event(e) {}
    ~FovEvent() {}
    bool accept(Manager &m) override;
};
#endif