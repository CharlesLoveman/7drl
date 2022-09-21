#ifndef __STATICSINGLERENDERER_H_
#define __STATICSINGLERENDERER_H_

#include "Renderer.hpp"
#include <memory>

class StaticSingleRenderer : public Renderer {
public:
    StaticSingleRenderer(tcod::Console &console);
    bool handleEvent(RenderEvent&) override;
};

#endif