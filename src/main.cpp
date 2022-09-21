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
#include "RandomTunnelGenerator.hpp"
#include "RenderEvent.hpp"
#include "SlimeGenerator.hpp"
#include "StaticSingleRenderer.hpp"



int main(int argc, char* argv[]) {
    DisplayConsole::initialise(argc, argv);
    auto map_renderer = std::make_shared<MapRenderer>(*DisplayConsole::getConsole());
    auto room_generator = std::make_shared<BasicRoomGenerator>();
    auto tunnel_generator = std::make_shared<RandomTunnelGenerator>();
    auto map_generator = std::make_shared<BSPRoomGenerator>(room_generator, tunnel_generator, 3, 10, 10, 1.5f, 1.5f);
    auto ssr = std::make_shared<StaticSingleRenderer>(*DisplayConsole::getConsole());
    auto slime_generator = std::make_shared<SlimeGenerator>(ssr);
    auto game_map = std::make_shared<GameMap>(DisplayConsole::WIDTH, DisplayConsole::HEIGHT, map_renderer, map_generator, slime_generator);

    auto m = std::make_shared<MovementManager>(*game_map);
    auto fov_manager = std::make_shared<FovManager>(*game_map);
    Entity player = Entity();
    player.subscribe(ssr);
    player.subscribe(m);
    player.subscribe(fov_manager);
    for (int i = 0; i < game_map->height; ++i) {
        for (int j = 0; j < game_map->width; ++j) {
            if (game_map->walkable(j, i)) {
                player.addComponent<Position>(j, i);
                break;
            }
        }
    }
    player.addComponent<Tile>(false, false, '@', Colour(0.0f, 0.0f, 0.0f), Colour(0.8f, 0.8f, 0.8f), Colour(0.0f, 0.0f, 0.0f), Colour(0.4f, 0.4f, 0.4f));
    player.addComponent<Fov>(8, true, FOV_RESTRICTIVE);
    RenderEvent render_player = RenderEvent(player);
    RenderEvent render_map = RenderEvent(*game_map);
    FovEvent fov_player = FovEvent(player);

    while (1) {
        TCOD_console_clear(DisplayConsole::getConsole()->get());
        player.raiseEvent(fov_player);
        game_map->raiseEvent(render_map);
        player.raiseEvent(render_player);
        DisplayConsole::getContext()->present(*DisplayConsole::getConsole());

        SDL_Event event;
        SDL_WaitEvent(nullptr);
        while(SDL_PollEvent(&event)) {
            DisplayConsole::getContext()->convert_event_coordinates(event);
            switch (event.type) {
                case SDL_QUIT:
                    return 0;
                case SDL_KEYDOWN:
                    {
                        int x = 0;
                        int y = 0;
                        switch (event.key.keysym.sym) {
                            case SDLK_h:
                                x -= 1;
                                break;
                            case SDLK_j:
                                y += 1;
                                break;
                            case SDLK_k:
                                y -= 1;
                                break;
                            case SDLK_l:
                                x += 1;
                                break;
                            case SDLK_y:
                                x -= 1;
                                y -= 1;
                                break;
                            case SDLK_u:
                                x += 1;
                                y -= 1;
                                break;
                            case SDLK_b:
                                x -= 1;
                                y += 1;
                                break;
                            case SDLK_n:
                                x += 1;
                                y += 1;
                                break;
                        }
                        MovementEvent move = MovementEvent(player, x, y);
                        player.raiseEvent(move);
                    }
            }
        }
    }
}