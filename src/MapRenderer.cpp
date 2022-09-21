#include "MapRenderer.hpp"
#include "GameMap.hpp"

bool MapRenderer::handleEvent(RenderEvent &event) {
    GameMap &map = GameMap::getInstance();
    char s[2];
    s[1] = '\0';
    for (int i = 0; i < map.height; ++i) {
        for (int j = 0; j < map.width; ++j) {
            if (map.visible(j, i)) {
                Tile t = map.tiles[i * map.width + j];
                s[0] = t.ch;
                tcod::print(*event.console, {j, i}, s, t.fg.toColor(), t.bg.toColor());
            } else if (map.seen[i * map.width + j]) {
                Tile t = map.tiles[i * map.width + j];
                s[0] = t.ch;
                tcod::print(*event.console, {j, i}, s, t.dark_fg.toColor(), t.dark_bg.toColor());
            } else {
                Tile t = map.Shroud();
                s[0] = t.ch;
                tcod::print(*event.console, {j, i}, s, t.dark_fg.toColor(), t.dark_bg.toColor());
            }
        }
    }
    return true;
}

std::shared_ptr<MapRenderer> MapRenderer::instance;
std::shared_ptr<MapRenderer> MapRenderer::getInstance() {
    if (!instance) {
        instance = std::make_shared<MapRenderer>();
    }
    return instance;
}