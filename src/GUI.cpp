#include "GUI.hpp"

#include <cstring>

void GUI::render(tcod::Console *console) {
    int offset = 0;
    tcod::print(*console, {x, y + offset++}, "<YOUR NAME HERE>", fg.toColor(), bg.toColor()); 
    StatBlock &stats = player.get<StatBlock>();
    char hp[20];
    sprintf(hp, "health: %d", stats.hp);
    tcod::print(*console, {x, y + offset++}, hp, fg.toColor(), bg.toColor()); 
    Weapons &weps = player.get<Weapons>();
    for (int i = 0; i < weps.weapons.size(); ++i) {
        tcod::print(*console, {x, y + offset++}, weps[i].describe(), fg.toColor(), bg.toColor());
    }
}