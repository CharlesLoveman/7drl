#ifndef __PLAYERUPDATE_H_
#define __PLAYERUPDATE_H_

#include "UpdateManager.hpp"
#include <memory>

class PlayerUpdate : public UpdateManager {
public:
    ~PlayerUpdate() {}
    bool handleEvent(UpdateEvent&) override; 
    static std::shared_ptr<PlayerUpdate> getInstance();
private:
    static std::shared_ptr<PlayerUpdate> instance;
};

#endif