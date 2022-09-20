#ifndef __ROOMGENERATOR_H_
#define __ROOMGENERATOR_H_

#include <vector>

struct Tile;

struct Room {
    int x, y, width, height;
    std::vector<Tile> tiles; 
};

class RoomGenerator {
public:
    virtual ~RoomGenerator() {}
    virtual Room generate(int x, int y, int width, int height) = 0;
};

#endif