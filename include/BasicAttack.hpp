#ifndef __BASICATTACK_H
#define __BASICATTACK_H

#include "AttackEvent.hpp"
#include "AttackManager.hpp"
#include <memory>

class BasicAttack : public AttackManager {
public:
    BasicAttack() : AttackManager() {}
    ~BasicAttack() {}
    bool handleEvent(AttackEvent&) override;
    static std::shared_ptr<BasicAttack> getInstance();
private:
    static std::shared_ptr<BasicAttack> instance;
};

#endif