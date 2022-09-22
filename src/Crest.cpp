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
void Aries::generate(Shots&) {
    std::cerr << "Generating Aries!\n";
}

void Aquarius::onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) {}

void Cancer::onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) {}

void Capricorn::generate(Shots&) {}

void Gemini::generate(Shots&) {}

void Leo::generate(Shots&) {}
void Leo::onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) {
    if (!hit) {
        if (GameMap::getInstance().in_bounds(x, y)) {
            GameMap::getInstance().set(x, y, GameMap::EmptyTile());
        }
    }
}

void Libra::generate(Shots&) {}

void Ophiucus::onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) {}

void Pisces::generate(Shots&) {}

void Sagittarius::generate(Shots&) {}

void Scorpio::onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) {}

void Taurus::generate(Shots&) {}

void Virgo::onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) {}