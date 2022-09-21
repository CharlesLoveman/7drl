#include "PlayerUpdate.hpp"
#include "Entity.hpp"
#include <SDL.h>

bool PlayerUpdate::handleEvent(UpdateEvent &e) {
    bool finished = false;
    do {
        SDL_Event event;
        SDL_WaitEvent(nullptr);
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
               case SDL_QUIT:
                    exit(0);
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
                    MovementEvent move = MovementEvent(e.entity, x, y);
                    e.entity.raiseEvent(move);
                    finished = true;
                }
            }
        }
    } while (!finished);
    return true;
}

std::shared_ptr<PlayerUpdate> PlayerUpdate::instance;
std::shared_ptr<PlayerUpdate> PlayerUpdate::getInstance() {
    if (!instance) {
        instance = std::make_shared<PlayerUpdate>();
    }
    return instance;
}