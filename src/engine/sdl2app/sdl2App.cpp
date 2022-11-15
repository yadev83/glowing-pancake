#include "sdl2App.hpp"

SDL2App::SDL2App(const int windowWidth, const int windowHeight, const char *windowName) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Could not initialize ! SDL_ERROR: " << SDL_GetError() << std::endl;
    } else {
        m_window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
        if(m_window == NULL) {
            std::cout << "SDL Window could not be created ! SDL_ERROR: " << SDL_GetError() << std::endl;
        }

        m_screenSurface = SDL_GetWindowSurface(m_window);
        SDL_FillRect(m_screenSurface, NULL, SDL_MapRGB(m_screenSurface->format, 0x40, 0x42, 0x54));
        SDL_UpdateWindowSurface(m_window);
    }
}

bool SDL2App::ready() {
    return m_window && m_screenSurface && !m_quit;
}

void SDL2App::Init() {}

void SDL2App::Update() {
    while(SDL_PollEvent(&m_sdlEvent)) {
        switch(m_sdlEvent.type) {
            case SDL_QUIT:
                m_quit = true;
        }
    }
}

void SDL2App::Draw() {}

void SDL2App::LateUpdate() {}

void SDL2App::Quit() {
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}