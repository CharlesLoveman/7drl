#ifndef __MOVEMENTMANAGER_H_
#define __MOVEMENTMANAGER_H_

#include "Manager.hpp"
#include "GameMap.hpp"

class MovementManager : public Manager {
public:
    MovementManager(GameMap &game_map) : Manager(), map(game_map) {}
    virtual ~MovementManager() {}
    virtual bool handleEvent(MovementEvent&) override;
private:
    GameMap &map;
};

#endif