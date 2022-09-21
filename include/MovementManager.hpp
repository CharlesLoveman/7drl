#ifndef __MOVEMENTMANAGER_H_
#define __MOVEMENTMANAGER_H_

#include "Manager.hpp"
#include "GameMap.hpp"

class MovementManager : public Manager {
public:
    MovementManager() : Manager() {}
    virtual ~MovementManager() {}
    virtual bool handleEvent(MovementEvent&) override;
    ManagerID id() override {return ManagerID::MOVEMENT;}
    static std::shared_ptr<MovementManager> getInstance();
private:
    static std::shared_ptr<MovementManager> instance;
};

#endif