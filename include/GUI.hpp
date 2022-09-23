#ifndef __GUI_H_
#define __GUI_H_

#include <Entity.hpp>
#include <libtcod.hpp>

class GUI {
public:
    GUI(Entity &_player, int _x, int _y) : player(_player), x(_x), y(_y), fg(Colour(1.0, 1.0, 1.0)), bg(Colour(0.0, 0.0, 0.0)) {}
    void render(tcod::Console *console);
private:
    Entity &player;
    int x, y;
    Colour fg, bg;
};

#endif