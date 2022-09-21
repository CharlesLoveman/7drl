#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "Manager.hpp"
#include <libtcod.hpp>

class Renderer : public Manager {
public:
    Renderer(tcod::Console &c) : console(c) {}
    virtual ~Renderer() {}
    virtual bool handleEvent(RenderEvent&) override = 0;
    ManagerID id() override {return ManagerID::RENDER;}
protected:
    tcod::Console &console;
};

#endif