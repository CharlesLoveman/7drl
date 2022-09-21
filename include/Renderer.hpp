#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "Manager.hpp"
#include <libtcod.hpp>

class Renderer : public Manager {
public:
    Renderer(tcod::Console &c) : console(c) {}
    virtual ~Renderer() {}
    virtual bool handleEvent(RenderEvent&) override = 0;
protected:
    tcod::Console &console;
};

#endif