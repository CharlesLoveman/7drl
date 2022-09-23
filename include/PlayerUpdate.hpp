#ifndef __PLAYERUPDATE_H_
#define __PLAYERUPDATE_H_

#include "Colour.hpp"
#include "UpdateManager.hpp"
#include <memory>

class PlayerUpdate : public UpdateManager {
public:
    ~PlayerUpdate() {
        delete player_console;
    }
    bool handleEvent(UpdateEvent&) override; 
    static std::shared_ptr<PlayerUpdate> getInstance();
    static void initialise(tcod::Console *_console, tcod::Context *_context, int _width, int _height) {
        console = _console;
        context = _context;
        width = _width;
        height = _height;
        player_console = new tcod::Console{width, height};
    }
private:
    static std::shared_ptr<PlayerUpdate> instance;
    static tcod::Console *console;
    static tcod::Context *context;
    static tcod::Console *player_console;
    static int width;
    static int height;
    static Colour key;
    bool fireWeapon(std::size_t weapon, Entity &player);
    void render();
};

#endif