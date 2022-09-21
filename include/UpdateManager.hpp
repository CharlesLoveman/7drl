#ifndef __UPDATEMANAGER_H_
#define __UPDATEMANAGER_H_

#include "Manager.hpp"

class UpdateManager : public Manager {
public:
    virtual ~UpdateManager() {}
    virtual bool handleEvent(UpdateEvent&) override = 0;
    ManagerID id() override {return ManagerID::UPDATE;}
};

#endif