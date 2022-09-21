#include "MapRenderer.hpp"
#include "GameMap.hpp"

MapRenderer::MapRenderer(tcod::Console *console) : Renderer(console) {}

#include <iostream>

bool MapRenderer::handleEvent(RenderEvent &event) {
    GameMap *map = (GameMap*) event.entity;
    char s[2];
    s[1] = '\0';
    for (int i = 0; i < map->height; ++i) {
        for (int j = 0; j < map->width; ++j) {
            if (map->map->isInFov(j, i)) {
                Tile t = map->tiles[i * map->width + j];
                s[0] = t.ch;
                tcod::print(*console, {j, i}, s, t.fg.toColor(), t.bg.toColor());
                //std::cerr << "MapRenderer\n";
                //std::cerr << (int) t.bg.r << ", " << (int) t.bg.g << ", " << (int) t.bg.b << "\n";
            } else if (map->seen[i * map->width + j]) {
                Tile t = map->tiles[i * map->width + j];
                s[0] = t.ch;
                tcod::print(*console, {j, i}, s, t.dark_fg.toColor(), t.dark_bg.toColor());
            } else {
                Tile t = map->Shroud();
                s[0] = t.ch;
                tcod::print(*console, {j, i}, s, t.dark_fg.toColor(), t.dark_bg.toColor());
            }

        }
    }
    return true;
}