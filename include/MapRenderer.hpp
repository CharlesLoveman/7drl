#ifndef __MAPRENDERER_H_
#define __MAPRENDERER_H_

#include "Renderer.hpp"

class MapRenderer : public Renderer {
public:
    MapRenderer(tcod::Console &console) : Renderer(console) {}
    bool handleEvent(RenderEvent &event) override;
    tcod::Console mapConsole;
};

#endif