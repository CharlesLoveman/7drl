#ifndef __RENDEREVENT_H_
#define __RENDEREVENT_H_

#include "Event.hpp"
#include <libtcod.hpp>

class RenderEvent : public Event {
public:
    RenderEvent(Entity &e, tcod::Console *_console) : Event(e) {
        console = _console;
    }
    ~RenderEvent() {}
    bool accept(Manager &m) override;
    ManagerID id() override;
    tcod::Console *console;
};
#endif