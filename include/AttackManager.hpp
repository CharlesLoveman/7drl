#ifndef __ATTACKMANAGER_H_
#define __ATTACKMANAGER_H_

#include "Manager.hpp"

class AttackManager : public Manager {
public:
    AttackManager() : Manager() {}
    virtual ~AttackManager() {}
    virtual bool handleEvent(AttackEvent&) override = 0;
    ManagerID id() override {return ManagerID::ATTACK;}
};

#endif