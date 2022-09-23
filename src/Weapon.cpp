#include "Weapon.hpp"

#include "Crest.hpp"
#include "Entity.hpp"
#include "GameMap.hpp"
#include <Imath/ImathVec.h>
#include <Imath/ImathMatrix.h>
#include <SDL.h>

Shots::Shots(Entity &e, Weapon &w, int x, int y) : weapon(w), entity(e) {
    acc = w.acc;
    crit = w.crit;
    spread = w.spread;
    shots = w.shots;
    range = w.range;
    numDice = w.numDice;
    diceSize = w.diceSize;
    pen = w.pen;
    target_x = x;
    target_y = y;
    for (auto c : w.crests) {
        c->generate(*this);
    }
}

#include <iostream>

tcod::Console *Shots::console;
tcod::Context *Shots::context;
tcod::Console *Shots::shotConsole;
void Shots::fire() {
    Position &p = entity.get<Position>();
    Imath::Vec2<float> start (p.x, p.y);
    Imath::Vec2<float> target (target_x, target_y);
    Imath::Vec2<float> v = target - start;
    v.normalize();
    Imath::Matrix22<float> m (Imath::UNINITIALIZED);
    m.makeIdentity();
    Imath::Vec2<float> u;
    TCODRandom *rng = TCODRandom::getInstance();
    int dest_x, dest_y;

    TCOD_console_clear(shotConsole->get());
    for (int i = 0; i < shots; ++i) {
        m.setRotation(rng->getFloat(-spread, spread));
        u = start + range * v * m;
        dest_x = round(u.x);
        dest_y = round(u.y);
        int x, y;
        TCODLine::init(p.x, p.y, dest_x, dest_y);
        bool miss = true;
        int tpen = pen;
        int trange = range;
        while (!TCODLine::step(&x, &y) && tpen && trange) {
            if (GameMap::getInstance().visible(x, y)) {
                TCOD_console_put_char_ex(shotConsole->get(), x, y, weapon.ch, weapon.fg.toColor(), weapon.bg.toColor());
            }
            std::optional<std::reference_wrapper<Entity>> blocker;
            if (GameMap::getInstance().blocked(x, y, blocker)) {
                if (rng->getFloat(0.0f, 1.0f) < acc) {
                    miss = false;
                    int damage = 0;
                    for (int i = 0; i < numDice; ++i) {
                        damage += rng->get(1, diceSize);
                    }
                    if (rng->getFloat(0.0f, 1.0f) < crit) {
                        damage *= 2;
                    }
                    for (auto c : weapon.crests) {
                        c->onHit(*this, x, y, blocker, damage);
                    }
                    if (blocker) {
                        (*blocker).get().raiseEvent<DamageEvent>(damage);
                    }
                }
                tpen--;
                if (!blocker) tpen = 0;
            }
            trange--;
        }
        if (miss) {
            for (auto c : weapon.crests) {
                c->onMiss(*this);
            }
        }
    }
    TCOD_console_blit(shotConsole->get(), 0, 0, shotConsole->get_shape()[0], shotConsole->get_shape()[1], console->get(), 0, 0, 1, 0);
    context->present(*console);
    SDL_Delay(50);
}

std::unique_ptr<Shots> Weapon::generate(Entity &e, int x, int y) {
    return std::make_unique<Shots>(e, *this, x, y);
}

std::string Weapon::describe() {
    return name;
}

std::string Weapon::verbose() {
    return name;
}