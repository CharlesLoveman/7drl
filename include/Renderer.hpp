#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "Manager.hpp"
#include <libtcod.hpp>
#include <memory>

class Renderer : public Manager {
public:
    Renderer(tcod::Console *console);
    virtual ~Renderer();
    virtual bool handleEvent(RenderEvent&) override = 0;
protected:
    tcod::Console *console;
};

#endif