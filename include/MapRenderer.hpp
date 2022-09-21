#ifndef __MAPRENDERER_H_
#define __MAPRENDERER_H_

#include "Renderer.hpp"
#include <memory>

class MapRenderer : public Renderer {
public:
    ~MapRenderer() {}
    bool handleEvent(RenderEvent&) override;
    static std::shared_ptr<MapRenderer> getInstance();
private:
    static std::shared_ptr<MapRenderer> instance;
};
#endif