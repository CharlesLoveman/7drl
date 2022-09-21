#ifndef __DISPLAYCONSOLE_H_
#define __DISPLAYCONSOLE_H_

#include <libtcod.hpp>
#include <memory>
#include <SDL.h>

class DisplayConsole {
public:
    static void initialise(int argc, char *argv[]) {
        console = std::make_shared<tcod::Console>(WIDTH, HEIGHT);

        auto params = TCOD_ContextParams{};
        params.tcod_version = TCOD_COMPILEDVERSION;
        params.renderer_type = TCOD_RENDERER_SDL2;
        params.console = console->get();
        params.window_title = "Rougelike";
        params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
        params.vsync = true;
        params.argc = argc;
        params.argv = argv;

        context = std::make_shared<tcod::Context>(params);
    }
    static std::shared_ptr<tcod::Console> getConsole() {
        return console;
    }
    static std::shared_ptr<tcod::Context> getContext() {
        return context;
    }
    static constexpr int WIDTH = 80;
    static constexpr int HEIGHT = 25;
private:
    DisplayConsole();
    inline static std::shared_ptr<tcod::Console> console;
    inline static std::shared_ptr<tcod::Context> context;
};

#endif