#include "SlimeGenerator.hpp"

std::unique_ptr<Entity> SlimeGenerator::generate() {
    std::unique_ptr<Entity> e = std::make_unique<Entity>();
    e->addComponent<Position>(0, 0);
    e->addComponent<Tile>(false, false, 's', Colour(0.0f, 0.0f, 0.0f), Colour(0.8f, 0.8f, 0.8f), Colour(0.0f, 0.0f, 0.0f), Colour(0.4f, 0.4f, 0.4f));
    e->subscribe(renderer);
    return e;
}