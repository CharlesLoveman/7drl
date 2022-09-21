#include "StaticSingleRenderer.hpp"
#include "Components.hpp"
#include "Entity.hpp"
#include "RenderEvent.hpp"
#include <libtcod.hpp>

#include <iostream>

StaticSingleRenderer::StaticSingleRenderer(tcod::Console &_console, GameMap &_map) : Renderer(_console), map(_map) {}

bool StaticSingleRenderer::handleEvent(RenderEvent &event) {
    Position &position = event.entity.get<Position>();
    Tile tile = event.entity.get<Tile>();
    if (!map.visible(position.x, position.y)) {
        tile = GameMap::Shroud();
    }
    char s[2];
    s[0] = tile.ch;
    s[1] = '\0';
    tcod::print(console, {position.x, position.y}, s, tile.fg.toColor(), tile.bg.toColor());
    return true;
}