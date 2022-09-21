#ifndef __STATICSINGLERENDERER_H_
#define __STATICSINGLERENDERER_H_

#include "GameMap.hpp"
#include "Renderer.hpp"
#include <memory>

class StaticSingleRenderer : public Renderer {
public:
    StaticSingleRenderer(tcod::Console &console, GameMap &map);
    bool handleEvent(RenderEvent&) override;
private:
    GameMap &map;
};

#endif