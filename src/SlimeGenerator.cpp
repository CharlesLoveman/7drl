#include "SlimeGenerator.hpp"

void SlimeGenerator::generate(Room &room, std::unordered_set<std::unique_ptr<Entity>> &entities) {
    Point p;
    if (!randPos(room, entities, p)) return;
    std::unique_ptr<Entity> e = std::make_unique<Entity>();
    e->addComponent<Position>(p.x, p.y);
    e->addComponent<Tile>(false, false, 's', Colour(0.0f, 0.0f, 0.0f), Colour(0.8f, 0.8f, 0.8f), Colour(0.0f, 0.0f, 0.0f), Colour(0.4f, 0.4f, 0.4f));
    e->subscribe(renderer);
    entities.insert(std::move(e));
}