#include "GameMap.hpp"

#include "FovManager.hpp"
#include "MapRenderer.hpp"
#include "MovementManager.hpp"
#include "PlayerUpdate.hpp"
#include "StaticSingleRenderer.hpp"

GameMap::~GameMap() {}

GameMap* GameMap::instance;
GameMap::GameMap(int _width, int _height) : Entity() {
    instance = this;
    width = _width;
    height = _height;
    map = std::make_unique<TCODMap>(width, height);
    subscribe(MapRenderer::getInstance());
}

GameMap& GameMap::getInstance() {
    return *instance;
}

bool GameMap::in_bounds(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool GameMap::walkable(int x, int y) {
    return in_bounds(x, y) && tiles[y * width + x].walkable;
}

bool GameMap::visible(int x, int y) {
    return in_bounds(x, y) && map->isInFov(x, y);
}

bool GameMap::blocked(int x, int y, std::optional<std::reference_wrapper<Entity>> &blocker) {
    blocker = std::nullopt;
    if (!walkable(x, y)) 
        return true;
    if (player) {
        Position &playerpos = player->get<Position>();
        if (x == playerpos.x && y == playerpos.y) {
            blocker = std::optional<std::reference_wrapper<Entity>>(*player);
            return true;
        }
    }
    for (auto &&e : entities) {
        if (!e->hasComponent<Position>()) continue;
        Position &p = e->get<Position>();
        if (!p.blocks) continue;
        if (p.x == x && p.y == y) {
            blocker = std::optional<std::reference_wrapper<Entity>>(*e);
            return true;
        }
    } 
    return false;
}

void GameMap::set(int x, int y, const Tile &tile) {
    if (!in_bounds(x, y)) throw std::runtime_error("Tried to set tile not in bounds!");
    tiles[y * width + x] = tile;
    map->setProperties(x, y, tile.transparent, tile.walkable);
}

void GameMap::generate(std::shared_ptr<RoomGenerator> room_generator, std::shared_ptr<EntityGenerator> entity_generator) {
    tiles = std::vector<Tile>(width * height, WallTile());
    for (unsigned int i = 0; i < tiles.size(); ++i) {
        tiles[i].bg.shift(0.1f);
    }
    seen = std::vector<bool>(width * height, false);
    entities = std::unordered_set<std::unique_ptr<Entity>>();
    rooms = room_generator->generate(1, 1, width - 2, height - 2);
    for (auto r : rooms) {
        entity_generator->generate(r);
    }
}

void GameMap::createPlayer() {
    player = std::make_unique<Entity>();
    player->subscribe(StaticSingleRenderer::getInstance());
    player->subscribe(MovementManager::getInstance());
    player->subscribe(FovManager::getInstance());
    player->subscribe(PlayerUpdate::getInstance());
    player->addComponent<Position>(rooms[0].x + rooms[0].width / 2, rooms[0].y + rooms[0].height / 2);
    player->addComponent<Tile>(false, false, '@', Colour(0.0f, 0.0f, 0.0f), Colour(0.8f, 0.8f, 0.8f), Colour(0.0f, 0.0f, 0.0f), Colour(0.4f, 0.4f, 0.4f));
    player->addComponent<Fov>(8, true, FOV_RESTRICTIVE);
    FovEvent fov_player = FovEvent(*player);
    player->raiseEvent(fov_player);
}

void GameMap::render(tcod::Console *console) {
    RenderEvent render_map = RenderEvent(*this, console);
    raiseEvent(render_map);
    for (auto &&e : entities) {
        RenderEvent render_e = RenderEvent(*e, console);
        e->raiseEvent(render_e);
    }
    RenderEvent render_player = RenderEvent(*player, console);
    player->raiseEvent(render_player);
}

void GameMap::update() {
    UpdateEvent update_player = UpdateEvent(*player);
    player->raiseEvent(update_player);

    FovEvent fov_player = FovEvent(*player);
    player->raiseEvent(fov_player);

    for (auto &&e : GameMap::getInstance().entities) {
        UpdateEvent update = UpdateEvent(*e);
        e->raiseEvent(update);
    }
}