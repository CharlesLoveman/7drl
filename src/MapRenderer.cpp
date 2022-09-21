#include "MapRenderer.hpp"
#include "GameMap.hpp"

bool MapRenderer::handleEvent(RenderEvent &event) {
    GameMap &map = static_cast<GameMap&>(event.entity);
    char s[2];
    s[1] = '\0';
    for (int i = 0; i < map.height; ++i) {
        for (int j = 0; j < map.width; ++j) {
            if (map.map->isInFov(j, i)) {
                Tile t = map.tiles[i * map.width + j];
                s[0] = t.ch;
                tcod::print(console, {j, i}, s, t.fg.toColor(), t.bg.toColor());
            } else if (map.seen[i * map.width + j]) {
                Tile t = map.tiles[i * map.width + j];
                s[0] = t.ch;
                tcod::print(console, {j, i}, s, t.dark_fg.toColor(), t.dark_bg.toColor());
            } else {
                Tile t = map.Shroud();
                s[0] = t.ch;
                tcod::print(console, {j, i}, s, t.dark_fg.toColor(), t.dark_bg.toColor());
            }

        }
    }
    for (auto &&e : map.entities) {
        RenderEvent re = RenderEvent(*e);
        e->raiseEvent(re);
    }
    return true;
}