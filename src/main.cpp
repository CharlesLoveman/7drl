#include <SDL.h>
#include <libtcod.hpp>
#include <memory>

#include "BasicRoomGenerator.hpp"
#include "BSPRoomGenerator.hpp"
#include "Components.hpp"
#include "Entity.hpp"
#include "GameMap.hpp"
#include "MapRenderer.hpp"
#include "MovementManager.hpp"
#include "RenderEvent.hpp"
#include "StaticSingleRenderer.hpp"

constexpr int WIDTH = 80;
constexpr int HEIGHT = 25;

int main(int argc, char* argv[]) {
    auto console = tcod::Console{WIDTH, HEIGHT};

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

    MapRenderer map_renderer = MapRenderer(&console);
    BasicRoomGenerator room_generator = BasicRoomGenerator();
    BSPRoomGenerator map_generator = BSPRoomGenerator(&room_generator, 3, 10, 10, 1.5f, 1.5f);
    GameMap game_map = GameMap(WIDTH, HEIGHT, &map_renderer, &map_generator);

    StaticSingleRenderer r = StaticSingleRenderer(&console);
    MovementManager m = MovementManager(&game_map);
    Entity player = Entity();
    player.subscribe(&r);
    player.subscribe(&m);
    player.addComponent(Component::POSITION, std::vector<int>({0, 0}));
    player.addComponent(Component::TILE, std::vector<int>({'@'}));
        RenderEvent render_player = RenderEvent(&player);
    RenderEvent render_map = RenderEvent(&game_map);

    while (1) {
        TCOD_console_clear(console.get());
        game_map.raiseEvent(render_map);
        player.raiseEvent(render_player);
        context.present(console);

        SDL_Event event;
        SDL_WaitEvent(nullptr);
        while(SDL_PollEvent(&event)) {
            context.convert_event_coordinates(event);
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
                        }
                        MovementEvent move = MovementEvent(&player, x, y);
                        player.raiseEvent(move);
                    }
            }
        }
    }
}