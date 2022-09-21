#include "StaticSingleRenderer.hpp"
#include "Components.hpp"
#include "Entity.hpp"
#include "RenderEvent.hpp"
#include <libtcod.hpp>

StaticSingleRenderer::StaticSingleRenderer() : Renderer() {}

bool StaticSingleRenderer::handleEvent(RenderEvent &event) {
    Position &position = event.entity.get<Position>();
    Tile tile = event.entity.get<Tile>();
    if (!GameMap::getInstance().visible(position.x, position.y)) {
        tile = GameMap::Shroud();
    }
    char s[2];
    s[0] = tile.ch;
    s[1] = '\0';
    tcod::print(*event.console, {position.x, position.y}, s, tile.fg.toColor(), tile.bg.toColor());
    return true;
}

std::shared_ptr<StaticSingleRenderer> StaticSingleRenderer::instance;
std::shared_ptr<StaticSingleRenderer> StaticSingleRenderer::getInstance() {
    if (!instance) {
        instance = std::make_shared<StaticSingleRenderer>();
    }
    return instance;
}