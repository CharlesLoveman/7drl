#include "Crest.hpp"

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

void Aquarius::onHit(Shots&) {}

void Cancer::onHit(Shots&) {}

void Capricorn::generate(Shots&) {}

void Gemini::generate(Shots&) {}

void Leo::generate(Shots&) {}
void Leo::onHit(Shots&) {}

void Libra::generate(Shots&) {}

void Ophiucus::onHit(Shots&) {}

void Pisces::generate(Shots&) {}

void Sagittarius::generate(Shots&) {}

void Scorpio::onHit(Shots&) {}

void Taurus::generate(Shots&) {}

void Virgo::onHit(Shots&) {}