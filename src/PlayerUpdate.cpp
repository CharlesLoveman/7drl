#include "PlayerUpdate.hpp"

#include "Entity.hpp"
#include "GameMap.hpp"
#include <libtcod.hpp>
#include <SDL.h>

tcod::Console *PlayerUpdate::console;
tcod::Context *PlayerUpdate::context;
tcod::Console *PlayerUpdate::player_console;
int PlayerUpdate::height;
int PlayerUpdate::width;
Colour PlayerUpdate::key = Colour(0.0, 0.0, 0.0);

void PlayerUpdate::render() {
    GameMap::getInstance().blit(console);
    TCOD_ColorRGB k = key.toColor();
    TCOD_console_blit_key_color(player_console->get(), 0, 0, width, height, console->get(), 0, 0, 1, 1, &k);
    context->present(*console);
}

bool PlayerUpdate::handleEvent(UpdateEvent &e) {
    player_console->clear();
    while(1) {
start:
        SDL_Event event;
        SDL_WaitEvent(nullptr);
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
               case SDL_QUIT:
                    exit(0);
                case SDL_KEYDOWN:
                    {
                    int x = 0;
                    int y = 0;
                    switch (event.key.keysym.sym) {
                        case SDLK_h:
                            x -= 1;
                            break;
                        case SDLK_j:
                            y += 1;
                            break;
                        case SDLK_k:
                            y -= 1;
                            break;
                        case SDLK_l:
                            x += 1;
                            break;
                        case SDLK_y:
                            x -= 1;
                            y -= 1;
                            break;
                        case SDLK_u:
                            x += 1;
                            y -= 1;
                            break;
                        case SDLK_b:
                            x -= 1;
                            y += 1;
                            break;
                        case SDLK_n:
                            x += 1;
                            y += 1;
                            break;
                        case SDLK_PERIOD:
                            return true;
                        case SDLK_1:
                            if (fireWeapon(1, e.entity)) return true;
                            render();
                            goto start; 
                        case SDLK_2:
                            if (fireWeapon(2, e.entity)) return true;
                        default:
                            render();
                            goto start;
                    }
                    e.entity.raiseEvent<MovementEvent>(x, y);
                    return true;
                }
            }
        }
    }
    return true;
}

#include <Imath/ImathVec.h>
bool PlayerUpdate::fireWeapon(std::size_t weapon, Entity &player) {
    int x, y;
    Position &p = player.get<Position>();
    x = p.x;
    y = p.y;
    Weapons &w = player.get<Weapons>();
    int wep = 0; 
    if (weapon < w.weapons.size()) wep = weapon;
    Imath::Vec2<float> u(x, y);
    while (1) {
        TCOD_console_clear(player_console->get());
        Imath::Vec2<float> v(x, y);
        float dist = (v - u).length();
        TCODLine::init(p.x, p.y, x, y);
        int lx, ly;
        Colour col = (dist <= w[wep].range) ? Colour(1, 1, 1) : Colour(1, 0, 0);
        while (!TCODLine::step(&lx, &ly)) {
            tcod::print(*player_console, {lx, ly}, "*", Colour(0, 0, 0).toColor(), col.toColor());
        }
        render();
        SDL_Event event;
        SDL_WaitEvent(nullptr);
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_h:
                            x -= 1;
                            break;
                        case SDLK_j:
                            y += 1;
                            break;
                        case SDLK_k:
                            y -= 1;
                            break;
                        case SDLK_l:
                            x += 1;
                            break;
                        case SDLK_y:
                            x -= 1;
                            y -= 1;
                            break;
                        case SDLK_u:
                            x += 1;
                            y -= 1;
                            break;
                        case SDLK_b:
                            x -= 1;
                            y += 1;
                            break;
                        case SDLK_n:
                            x += 1;
                            y += 1;
                            break;
                        case SDLK_f:
                            player.raiseEvent<AttackEvent>(x, y, weapon);
                            return true;
                        default:
                            return false;
                    }
            }
        }
    }
}

std::shared_ptr<PlayerUpdate> PlayerUpdate::instance;
std::shared_ptr<PlayerUpdate> PlayerUpdate::getInstance() {
    if (!instance) {
        instance = std::make_shared<PlayerUpdate>();
    }
    return instance;
}