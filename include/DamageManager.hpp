#ifndef __DAMAGEMANAGER_H_
#define __DAMAGEMANAGER_H_

#include "Manager.hpp"

class DamageManager : public Manager {
public:
    DamageManager() : Manager() {}
    virtual ~DamageManager() {}
    virtual bool handleEvent(DamageEvent&) override;
    ManagerID id() override {return ManagerID::DAMAGE;}
    static std::shared_ptr<DamageManager> getInstance();
private:
    static std::shared_ptr<DamageManager> instance;
};

#endif