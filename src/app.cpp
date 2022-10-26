#include <iostream>
#include <functional>

#include <SDL2/SDL.h>

#include <engine/event/eventManager.hpp>
#include <engine/app/app.hpp>

#include <application/events/demoEvent.hpp>
#include <application/observers/demoObserver.hpp>

#include <application/utils/constants.hpp>

class SDL2App : public App {
    private:
        SDL_Window *m_window = NULL;
        SDL_Surface *m_screenSurface = NULL;
        SDL_Event m_sdlEvent;

    public:
        SDL2App(const int windowWidth, const int windowHeight, const char *windowName) {
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

        bool ready() {
            return m_window && m_screenSurface && !m_quit;
        }

        bool shouldQuit() {
            return m_quit;
        }

        void Init() {

        }

        void Update() {
            while(SDL_PollEvent(&m_sdlEvent)) {
                switch(m_sdlEvent.type) {
                    case SDL_QUIT:
                        m_quit = true;
                }
            }
        }

        void Draw() {

        }

        void LateUpdate() {

        }

        void Quit() {
            SDL_DestroyWindow(m_window);
            SDL_Quit();
        }
};

int main(int argc, char *argv[]) {
    App *app = new SDL2App(SCREEN_WIDTH, SCREEN_HEIGHT, APP_NAME);

    if(app->ready()) {
        app->Init();

        while(!app->shouldQuit()) {
            app->Update();
            app->Draw();
            app->LateUpdate();
        }

        app->Quit();
    }

    return 0;
}