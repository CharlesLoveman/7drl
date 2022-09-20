#include "BasicRoomGenerator.hpp"

#include "GameMap.hpp"

BasicRoomGenerator::BasicRoomGenerator() {
    rng = TCODRandom::getInstance();
}

Room BasicRoomGenerator::generate(int x, int y, int width, int height) {
    int start_x = rng->get(x, x + width - 2);
    int start_y = rng->get(y, y + height - 2);
    int room_width = rng->get(3, width - 2 - start_x);
    int room_height = rng->get(3, height - 2 - start_y);
    std::vector<Tile> tiles = std::vector<Tile>(room_width * room_height);
    fill(tiles.begin(), tiles.end(), GameMap::EmptyTile);
    for (int i = 0; i < room_width; ++i) {
        tiles[i] = GameMap::WallTile;
        tiles[(room_height - 1) * room_width + i] = GameMap::WallTile;
    }
    for (int i = 0; i < room_height; ++i) {
        tiles[i * room_width] = GameMap::WallTile;
        tiles[i * room_width + room_width - 1] = GameMap::WallTile;
    }
    return {start_x, start_y, room_width, room_height, tiles};
}