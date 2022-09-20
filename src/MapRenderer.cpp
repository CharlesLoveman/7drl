#include "MapRenderer.hpp"
#include "GameMap.hpp"

MapRenderer::MapRenderer(tcod::Console *console) : Renderer(console) {}

bool MapRenderer::handleEvent(RenderEvent &event) {
    GameMap *map = (GameMap*) event.entity;
    char s[2];
    s[1] = '\0';
    for (int i = 0; i < map->height; ++i) {
        for (int j = 0; j < map->width; ++j) {
            Tile t = map->tiles[i * map->width + j];
            s[0] = t.ch;
            tcod::print(*console, {j, i}, s, t.fg.toColor(), t.bg.toColor());
        }
    }
    return true;
}