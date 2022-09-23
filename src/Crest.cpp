#include "Crest.hpp"

#include "GameMap.hpp"

#define SINGLETON(T) \
    std::shared_ptr<T> T::instance; \
    std::shared_ptr<T> T::getInstance() { \
        if (!instance) instance = std::make_shared<T>(); \
        return instance; \
    }

SINGLETON(Aries)
SINGLETON(Aquarius)
SINGLETON(Cancer)
SINGLETON(Capricorn)
SINGLETON(Gemini)
SINGLETON(Leo)
SINGLETON(Libra)
SINGLETON(Ophiucus)
SINGLETON(Pisces)
SINGLETON(Sagittarius)
SINGLETON(Scorpio)
SINGLETON(Taurus)
SINGLETON(Virgo)

#include <iostream>
void Aries::generate(Shots &s) {
    s.pen *= 2;
}

void Aquarius::onHit(Shots&, int, int, std::optional<std::reference_wrapper<Entity>>, int) {}

void Cancer::onHit(Shots&, int, int, std::optional<std::reference_wrapper<Entity>>, int) {}

void Capricorn::generate(Shots &s) {
    s.numDice /= 2;
    if (s.numDice == 0) s.numDice = 1;
    s.diceSize *= 2.5;
}

void Gemini::generate(Shots &s) {
    s.shots *= 1.5;
    s.spread *= 1.5;
}

void Leo::generate(Shots &s) {
    s.diceSize++;
}
void Leo::onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit, int) {
    if (!hit) {
        if (GameMap::getInstance().in_bounds(x, y)) {
            GameMap::getInstance().set(x, y, GameMap::EmptyTile());
        }
    }
    //else add fire
}

void Libra::generate(Shots &s) {
    float sum = 0.0f;
    sum += 10.0f * s.acc;
    sum += 10.0f * s.numDice;
    sum += s.diceSize;
    sum += 5 * s.shots;
    sum += 10 * s.spread;
    sum += 10 * s.crit;
    sum += s.range;

    s.acc = sum / 70.0f;
    s.numDice = ceil(sum / 70.0f);
    s.diceSize = ceil(sum / 7.0f);
    s.shots = ceil(sum / 35.0f);
    s.spread = sum / 70.0f;
    s.crit = sum / 70.0f;
    s.range = sum / 7.0f;
}

void Ophiucus::onHit(Shots &s, int, int, std::optional<std::reference_wrapper<Entity>>, int damage) {
    StatBlock &stats = s.entity.get<StatBlock>();
    stats.hp += damage;
}

void Pisces::generate(Shots&) {}

void Sagittarius::generate(Shots&) {}

void Scorpio::onHit(Shots&, int, int, std::optional<std::reference_wrapper<Entity>>, int) {}

void Taurus::generate(Shots&) {}

void Virgo::onHit(Shots&, int, int, std::optional<std::reference_wrapper<Entity>>, int) {}