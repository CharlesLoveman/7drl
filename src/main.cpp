#include <SDL.h>
#include <libtcod.hpp>
#include <memory>

#include "BasicRoomGenerator.hpp"
#include "BSPRoomGenerator.hpp"
#include "Components.hpp"
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

#include <iostream>

constexpr int WIDTH = 80;
constexpr int HEIGHT = 25;

int main(int argc, char* argv[]) {
    auto console = tcod::Console(WIDTH, HEIGHT);

    auto params = TCOD_ContextParams{};
    params.tcod_version = TCOD_COMPILEDVERSION;
    params.renderer_type = TCOD_RENDERER_SDL2;
    params.console = console.get();
    params.window_title = "Rougelike";
    params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
    params.vsync = true;
    params.argc = argc;
    params.argv = argv;

    auto context = tcod::Context(params);

    auto room_generator = std::make_shared<BasicRoomGenerator>();
    auto tunnel_generator = std::make_shared<RandomTunnelGenerator>();
    auto map_generator = std::make_shared<BSPRoomGenerator>(room_generator, tunnel_generator, 3, 10, 10, 1.5f, 1.5f);
    auto slime_generator = std::make_shared<SlimeGenerator>();
    GameMap game_map = GameMap(WIDTH, HEIGHT);
    game_map.generate(map_generator, slime_generator);
    game_map.createPlayer();
    while (1) {
        TCOD_console_clear(console.get());
        game_map.render(&console);
        context.present(console);
        game_map.update();
    }
}