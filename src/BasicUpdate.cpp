#include "BasicUpdate.hpp"

#include "Entity.hpp"
#include "GameMap.hpp"
#include "MovementEvent.hpp"
#include <libtcod.hpp>

#include <iostream>

TCODPath *get_path(TCODMap *path_map, int ox, int oy, int dx, int dy) {
    GameMap &map = GameMap::getInstance();
    path_map->copy(map.map.get());
    for (auto &&e: map.entities) {
        if (e->hasComponent<Position>()) {
            Position &p = e->get<Position>();
            path_map->setProperties(p.x, p.y, false, true);
        }
    }
    path_map->setProperties(ox, oy, true, true);
    TCODPath *path = new TCODPath(path_map);
    path->compute(ox, oy, dx, dy);
    return path;
}

bool BasicUpdate::handleEvent(UpdateEvent &event) {
    TCODRandom *rng = TCODRandom::getInstance();
    Position &p = event.entity.get<Position>();
    GameMap &map = GameMap::getInstance();
    if (map.visible(p.x, p.y)) {
        Position &pp = GameMap::getInstance().player->get<Position>();
        TCODMap *path_map = new TCODMap(map.width, map.height);
        TCODPath *path = get_path(path_map, p.x, p.y, pp.x, pp.y);        
        int x, y;
        while (path->walk(&x, &y, false)) {
            event.entity.raiseEvent<MovementEvent>(x - p.x, y - p.y);
            break;
        }
        delete path;
        delete path_map;
    } else {
        event.entity.raiseEvent<MovementEvent>(rng->get(-1,1), rng->get(-1,1));
    }
    return true;
}

std::shared_ptr<BasicUpdate> BasicUpdate::instance;
std::shared_ptr<BasicUpdate> BasicUpdate::getInstance() {
    if (!instance) {
        instance = std::make_shared<BasicUpdate>();
    }
    return instance;
}