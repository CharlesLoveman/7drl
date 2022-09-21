#ifndef __MOVEMENTEVENT_H_
#define __MOVEMENTEVENT_H_

#include "Event.hpp"

class MovementEvent : public Event {
public:
    MovementEvent(Entity &e, int _x, int _y) : Event(e) {
        x = _x;
        y = _y;
    }
    ~MovementEvent() {}
    int x;
    int y;
    bool accept(Manager&) override;
};
#endif