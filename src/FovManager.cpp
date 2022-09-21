#include "FovManager.hpp"

#include "Components.hpp"

bool FovManager::handleEvent(FovEvent &event) {
    Position &position = event.entity.get<Position>();
    Fov &fov = event.entity.get<Fov>();
    map.map->computeFov(position.x, position.y, fov.radius, fov.light_walls, fov.algo);
    for (unsigned int i = 0; i < map.tiles.size(); ++i) {
        if (!map.seen[i] && map.visible(i % map.width, i / map.width)) {
            map.seen[i] = true;
        }
    }
    return true;
}