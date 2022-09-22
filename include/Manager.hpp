#ifndef __MANAGER_H_
#define __MANAGER_H_

#include "AttackEvent.hpp"
#include "DamageEvent.hpp"
#include "FovEvent.hpp"
#include "MovementEvent.hpp"
#include "RenderEvent.hpp"
#include "UpdateEvent.hpp"

enum class ManagerID {
    RENDER,
    MOVEMENT,
    FOV,
    UPDATE,
    ATTACK,
    DAMAGE,
};

class Manager {
public:
    virtual ~Manager() {}
    virtual bool handleEvent(RenderEvent&) {return false;}
    virtual bool handleEvent(MovementEvent&) {return false;}
    virtual bool handleEvent(FovEvent&) {return false;}
    virtual bool handleEvent(UpdateEvent&) {return false;}
    virtual bool handleEvent(AttackEvent&) {return false;}
    virtual bool handleEvent(DamageEvent&) {return false;}
    virtual ManagerID id() = 0;
};

#endif