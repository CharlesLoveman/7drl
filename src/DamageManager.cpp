#include "DamageManager.hpp"

#include "Components.hpp"
#include "Entity.hpp"
#include "GameMap.hpp"

bool DamageManager::handleEvent(DamageEvent &event) {
    StatBlock& stats = event.entity.get<StatBlock>();
    stats.hp -= event.damage;
    if (stats.hp <= 0) {
        GameMap &map = GameMap::getInstance();
        for (auto &&e : map.entities) {
            if (e->getId() == event.entity.getId()) {
                map.entities.erase(e);
                break;
            }
        }
    }
    return true;
}

std::shared_ptr<DamageManager> DamageManager::instance;
std::shared_ptr<DamageManager> DamageManager::getInstance() {
    if (!instance) {
        instance = std::make_shared<DamageManager>();
    }
    return instance;
}