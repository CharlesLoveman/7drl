#ifndef __MANAGER_H_
#define __MANAGER_H_

#include "RenderEvent.hpp"
#include "MovementEvent.hpp"

class Manager {
public:
    virtual ~Manager();
    virtual bool handleEvent(RenderEvent&);
    virtual bool handleEvent(MovementEvent&);
};

#endif