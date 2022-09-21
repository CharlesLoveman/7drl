#ifndef __ROOMGENERATOR_H_
#define __ROOMGENERATOR_H_

#include <libtcod.hpp>
#include <vector>

struct Point {
    int x, y;
};

struct Room {
    int x, y, width, height;
    Point centre() {
        return {x + width / 2, y + height / 2};
    }
    Point random() {
        TCODRandom *rng = TCODRandom::getInstance();
        return {rng->get(x, x + width - 1), rng->get(y, y + height - 1)};
    }
};

class RoomGenerator {
public:
    virtual ~RoomGenerator() {}
    virtual std::vector<Room> generate(int x, int y, int width, int height) = 0;
};

#endif