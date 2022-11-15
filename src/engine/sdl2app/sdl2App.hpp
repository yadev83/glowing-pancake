#ifndef SDL2APP_H
#define SDL2APP_H

#include <iostream>

#include <SDL2/SDL.h>

#include <engine/app/app.hpp>

class SDL2App : public App {
    private:
        SDL_Window *m_window = NULL;
        SDL_Surface *m_screenSurface = NULL;
        SDL_Event m_sdlEvent;

    public:
        SDL2App(const int windowWidth, const int windowHeight, const char *windowName);
        bool ready();

        void Init();
        virtual void Update();
        virtual void Draw();
        virtual void LateUpdate();
        virtual void Quit();
};

#endif