#include <iostream>
#include <functional>

#include <engine/event/eventManager.hpp>
#include <engine/app/app.hpp>

#include <application/events/demoEvent.hpp>
#include <application/observers/demoObserver.hpp>
#include <application/sdl2app/sdl2App.hpp>

#include <application/utils/constants.hpp>

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