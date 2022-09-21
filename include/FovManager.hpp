#ifndef __FOVMANAGER_H_
#define __FOVMANAGER_H_

#include "Manager.hpp"
#include "GameMap.hpp"

class FovManager : public Manager {
public:
    FovManager() : Manager() {}
    virtual ~FovManager() {}
    virtual bool handleEvent(FovEvent&) override;
    ManagerID id() override {return ManagerID::FOV;}
    static std::shared_ptr<FovManager> getInstance();
private:
    static std::shared_ptr<FovManager> instance;
};

#endif