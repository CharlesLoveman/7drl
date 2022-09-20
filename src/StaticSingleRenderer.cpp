#include "StaticSingleRenderer.hpp"
#include "Components.hpp"
#include "Entity.hpp"
#include "RenderEvent.hpp"
#include <libtcod.hpp>

#include <iostream>

StaticSingleRenderer::StaticSingleRenderer(tcod::Console *_console) : Renderer(_console) {}

bool StaticSingleRenderer::handleEvent(RenderEvent &event) {
    Entity *e= event.entity;
    Position *position = dynamic_cast<Position*>(e->get(Components::POSITION));
    if (!position) throw std::invalid_argument("Position Component was not Position!");
    Tile *tile = dynamic_cast<Tile*>(e->get(Components::TILE));
    if (!tile) throw std::invalid_argument("Tile Component was not Tile!");
    char s[2];
    s[0] = tile->ch;
    s[1] = '\0';
    tcod::print(*console, {position->x, position->y}, s, tile->fg.toColor(), tile->bg.toColor());
    return true;
}