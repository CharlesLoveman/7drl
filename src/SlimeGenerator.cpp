#include "SlimeGenerator.hpp"

#include "GameMap.hpp"

void SlimeGenerator::generate(Room &room, GameMap &map) {
    Point p;
    if (!randPos(room, map, p)) return;
    std::unique_ptr<Entity> e = std::make_unique<Entity>();
    e->addComponent<Position>(p.x, p.y);
    e->addComponent<Tile>(false, false, 's', Colour(0.0f, 0.0f, 0.0f), Colour(0.8f, 0.8f, 0.8f), Colour(0.0f, 0.0f, 0.0f), Colour(0.4f, 0.4f, 0.4f));
    e->subscribe(renderer);
    map.entities.insert(std::move(e));
}