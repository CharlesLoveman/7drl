#include <SDL.h>
#include <libtcod.hpp>
#include <memory>

#include "BasicRoomGenerator.hpp"
#include "BSPRoomGenerator.hpp"
#include "Components.hpp"
#include "DisplayConsole.hpp"
#include "Entity.hpp"
#include "FovEvent.hpp"
#include "FovManager.hpp"
#include "GameMap.hpp"
#include "MapRenderer.hpp"
#include "MovementManager.hpp"
#include "PlayerUpdate.hpp"
#include "RandomTunnelGenerator.hpp"
#include "RenderEvent.hpp"
#include "SlimeGenerator.hpp"
#include "StaticSingleRenderer.hpp"
#include "UpdateEvent.hpp"


int main(int argc, char* argv[]) {
    DisplayConsole::initialise(argc, argv);
    auto map_renderer = std::make_shared<MapRenderer>(*DisplayConsole::getConsole());
    auto room_generator = std::make_shared<BasicRoomGenerator>();
    auto tunnel_generator = std::make_shared<RandomTunnelGenerator>();
    auto map_generator = std::make_shared<BSPRoomGenerator>(room_generator, tunnel_generator, 3, 10, 10, 1.5f, 1.5f);
    auto game_map = std::make_shared<GameMap>(DisplayConsole::WIDTH, DisplayConsole::HEIGHT, map_renderer);
    auto ssr = std::make_shared<StaticSingleRenderer>(*DisplayConsole::getConsole(), *game_map);
    auto slime_generator = std::make_shared<SlimeGenerator>(ssr);
    game_map->generate(map_generator, slime_generator);

    auto m = std::make_shared<MovementManager>(*game_map);
    auto fov_manager = std::make_shared<FovManager>(*game_map);
    auto player_update = std::make_shared<PlayerUpdate>();
    Entity player = Entity();
    player.subscribe(ssr);
    player.subscribe(m);
    player.subscribe(fov_manager);
    player.subscribe(player_update);
    player.addComponent<Position>(game_map->rooms[0].x + game_map->rooms[0].width / 2, game_map->rooms[0].y + game_map->rooms[0].height / 2);
    player.addComponent<Tile>(false, false, '@', Colour(0.0f, 0.0f, 0.0f), Colour(0.8f, 0.8f, 0.8f), Colour(0.0f, 0.0f, 0.0f), Colour(0.4f, 0.4f, 0.4f));
    player.addComponent<Fov>(8, true, FOV_RESTRICTIVE);
    RenderEvent render_player = RenderEvent(player);
    RenderEvent render_map = RenderEvent(*game_map);
    FovEvent fov_player = FovEvent(player);
    UpdateEvent update_player = UpdateEvent(player);

    while (1) {
        player.raiseEvent(update_player);
        player.raiseEvent(fov_player);
        TCOD_console_clear(DisplayConsole::getConsole()->get());
        game_map->raiseEvent(render_map);
        player.raiseEvent(render_player);
        DisplayConsole::getContext()->present(*DisplayConsole::getConsole());
    }
}