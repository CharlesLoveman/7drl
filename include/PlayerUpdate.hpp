#ifndef __PLAYERUPDATE_H_
#define __PLAYERUPDATE_H_

#include "UpdateManager.hpp"

class PlayerUpdate : public UpdateManager {
public:
    ~PlayerUpdate() {}
    bool handleEvent(UpdateEvent&) override; 
};

#endif