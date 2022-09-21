#ifndef __FOVMANAGER_H_
#define __FOVMANAGER_H_

#include "Manager.hpp"
#include "GameMap.hpp"

class FovManager : public Manager {
public:
    FovManager(GameMap &game_map) : Manager(), map(game_map) {}
    virtual ~FovManager() {}
    virtual bool handleEvent(FovEvent&) override;
private:
    GameMap &map;
};

#endif