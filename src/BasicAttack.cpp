#include "BasicAttack.hpp"

#include "Entity.hpp"
#include "Weapon.hpp"

bool BasicAttack::handleEvent(AttackEvent &event) {
    Weapons &weapons = event.entity.get<Weapons>();
    int weapon = 0;
    if (event.weapon < weapons.weapons.size()) {
        weapon = event.weapon;
    }
    weapons[weapon].generate(event.entity, event.target_x, event.target_y)->fire();
    return true;
}

std::shared_ptr<BasicAttack> BasicAttack::instance;
std::shared_ptr<BasicAttack> BasicAttack::getInstance() {
    if (!instance) {
        instance = std::make_shared<BasicAttack>();
    }
    return instance;
}