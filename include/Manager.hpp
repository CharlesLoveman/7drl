#ifndef __MANAGER_H_
#define __MANAGER_H_

#include "FovEvent.hpp"
#include "MovementEvent.hpp"
#include "RenderEvent.hpp"

class Manager {
public:
    virtual ~Manager();
    virtual bool handleEvent(RenderEvent&);
    virtual bool handleEvent(MovementEvent&);
    virtual bool handleEvent(FovEvent&);
};

#endif