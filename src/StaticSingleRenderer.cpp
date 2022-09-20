#include "StaticSingleRenderer.hpp"
#include "Components.hpp"
#include "Entity.hpp"
#include "RenderEvent.hpp"
#include <libtcod.hpp>

#include <iostream>

StaticSingleRenderer::StaticSingleRenderer(tcod::Console *_console) : Renderer(_console) {}

bool StaticSingleRenderer::handleEvent(RenderEvent &event) {
    Entity *e= event.entity;
    auto position = e->get(Component::POSITION);
    auto tile = e->get(Component::TILE);
    char s[2];
    s[0] = (char) (*tile)[0];
    s[1] = '\0';
    tcod::print(*console, {(*position)[0], (*position)[1]}, s, std::nullopt, std::nullopt);
    return true;
}