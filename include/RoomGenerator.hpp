#ifndef __ROOMGENERATOR_H_
#define __ROOMGENERATOR_H_

#include <vector>

class GameMap;

struct Room {
    int x, y, width, height;
};

class RoomGenerator {
public:
    virtual ~RoomGenerator() {}
    virtual Room generate(int x, int y, int width, int height, GameMap &map) = 0;
};

#endif