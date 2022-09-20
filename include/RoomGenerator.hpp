#ifndef __ROOMGENERATOR_H_
#define __ROOMGENERATOR_H_

#include <vector>

struct Tile;

struct Room {
    int x, y, width, height;
};

class RoomGenerator {
public:
    virtual ~RoomGenerator() {}
    virtual Room generate(int x, int y, int width, int height, std::vector<Tile> *source, int source_width) = 0;
};

#endif