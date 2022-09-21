#ifndef __BASICUPDATE_H_
#define __BASICUPDATE_H_

#include "UpdateManager.hpp"
#include <memory>

class BasicUpdate : public UpdateManager {
public:
    ~BasicUpdate() {}
    bool handleEvent(UpdateEvent&) override; 
    static std::shared_ptr<BasicUpdate> getInstance();
private:
    static std::shared_ptr<BasicUpdate> instance;
};

#endif