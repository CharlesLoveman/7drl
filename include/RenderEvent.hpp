#ifndef __RENDEREVENT_H_
#define __RENDEREVENT_H_

#include "Event.hpp"

class RenderEvent : public Event {
public:
    RenderEvent(Entity &e) : Event(e) {}
    ~RenderEvent() {}
    bool accept(Manager &m) override;
};
#endif