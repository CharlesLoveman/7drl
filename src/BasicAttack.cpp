#include "BasicAttack.hpp"

#include "Entity.hpp"
#include "Weapon.hpp"

bool BasicAttack::handleEvent(AttackEvent &event) {
    Weapons &weapons = event.entity.get<Weapons>();
    Position &p = event.target.get<Position>();
    weapons[event.weapon].generate(event.entity, p.x, p.y)->fire();
    return true;
}

std::shared_ptr<BasicAttack> BasicAttack::instance;
std::shared_ptr<BasicAttack> BasicAttack::getInstance() {
    if (!instance) {
        instance = std::make_shared<BasicAttack>();
    }
    return instance;
}