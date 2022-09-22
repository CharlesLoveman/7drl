#ifndef __PLAYERUPDATE_H_
#define __PLAYERUPDATE_H_

#include "UpdateManager.hpp"
#include <memory>

class PlayerUpdate : public UpdateManager {
public:
    ~PlayerUpdate() {}
    bool handleEvent(UpdateEvent&) override; 
    static std::shared_ptr<PlayerUpdate> getInstance();
    static void initialise(tcod::Console *_console, tcod::Context *_context) {
        console = _console;
        context = _context;
    }
private:
    static std::shared_ptr<PlayerUpdate> instance;
    static tcod::Console *console;
    static tcod::Context *context;
    bool fireWeapon(std::size_t weapon, Entity &player);
};

#endif