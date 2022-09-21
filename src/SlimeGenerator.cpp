#include "SlimeGenerator.hpp"

#include "BasicUpdate.hpp"
#include "GameMap.hpp"
#include "MovementManager.hpp"
#include "StaticSingleRenderer.hpp"

void SlimeGenerator::generate(Room &room) {
    Point p;
    if (!randPos(room, p)) return;
    std::unique_ptr<Entity> e = std::make_unique<Entity>();
    e->addComponent<Position>(p.x, p.y);
    e->addComponent<Tile>(false, false, 's', Colour(0.0f, 0.0f, 0.0f), Colour(0.8f, 0.8f, 0.8f), Colour(0.0f, 0.0f, 0.0f), Colour(0.4f, 0.4f, 0.4f));
    e->subscribe(StaticSingleRenderer::getInstance());
    e->subscribe(BasicUpdate::getInstance());
    e->subscribe(MovementManager::getInstance());
    GameMap::getInstance().entities.insert(std::move(e));
}