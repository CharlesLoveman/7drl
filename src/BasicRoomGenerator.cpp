#include "BasicRoomGenerator.hpp"

#include "GameMap.hpp"

BasicRoomGenerator::BasicRoomGenerator() {
    rng = TCODRandom::getInstance();
}

Room BasicRoomGenerator::generate(int x, int y, int width, int height, std::vector<Tile> *source, int source_width) {
    int start_x = rng->get(x, x + width - 3);
    int start_y = rng->get(y, y + height - 3);
    int room_width = rng->get(3, width - (start_x - x));
    int room_height = rng->get(3, height - (start_y - y));
    for (int i = 0; i < room_height; ++i) {
        for (int j = 0; j < room_width; ++j) {
            (*source)[(start_y + i) * source_width + start_x + j] = GameMap::EmptyTile;
        }
    }
    return {start_x, start_y, room_width, room_height};
}