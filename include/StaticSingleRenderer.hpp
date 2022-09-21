#ifndef __STATICSINGLERENDERER_H_
#define __STATICSINGLERENDERER_H_

#include "GameMap.hpp"
#include "Renderer.hpp"
#include <memory>

class StaticSingleRenderer : public Renderer {
public:
    StaticSingleRenderer();
    bool handleEvent(RenderEvent&) override;
    static std::shared_ptr<StaticSingleRenderer> getInstance();
private:
    static std::shared_ptr<StaticSingleRenderer> instance;
};

#endif