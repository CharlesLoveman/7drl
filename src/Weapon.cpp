#include "Weapon.hpp"

#include "Crest.hpp"
#include "Entity.hpp"
#include "GameMap.hpp"
#include <Imath/ImathVec.h>
#include <Imath/ImathMatrix.h>

Shots::Shots(Entity &e, const Weapon &w, int x, int y) : weapon(w), entity(e) {
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
                        c->onHit(*this, x, y, blocker);
                    }
                    if (blocker) {
                        (*blocker).get().raiseEvent<DamageEvent>(damage);
                    }
                }
                tpen--;
            }
            trange--;
        }
        if (miss) {
            for (auto c : weapon.crests) {
                c->onMiss(*this);
            }
        }
    }
}

std::unique_ptr<Shots> Weapon::generate(Entity &e, int x, int y) const {
    return std::make_unique<Shots>(e, *this, x, y);
}

std::string Weapon::describe() {
    return name;
}

std::string Weapon::verbose() {
    return name;
}