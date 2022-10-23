#include <iostream>
#include <functional>

#include <SDL2/SDL.h>

#include <utils/constants.hpp>
#include <utils/event/eventManager.hpp>

#include <application/events/demoEvent.hpp>
#include <application/observers/demoObserver.hpp>

using namespace std::placeholders;

int main(int argc, char *argv[]) {
    EventManager eventManager;
    DemoObserver observer;

    eventManager.subscribe(DemoEvent::id, std::bind(&DemoObserver::onDemoEvent, observer, _1));
    eventManager.dispatch(DemoEvent());

    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Could not initialize ! SDL_ERROR: " << SDL_GetError() << std::endl;
    } else {
        window = SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL)
            std::cout << "Window could not be created ! SDL_ERROR: " << SDL_GetError() << std::endl;

        screenSurface = SDL_GetWindowSurface(window);
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x40, 0x42, 0x54));
        SDL_UpdateWindowSurface(window);

        SDL_Event e;
        bool quit = false;

        while(!quit) {
            while(SDL_PollEvent(&e)) {
                switch(e.type) {
                    case SDL_QUIT:
                        quit = true;
                }
            }
        }

        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    return 0;
}