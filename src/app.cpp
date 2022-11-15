#include <iostream>
#include <functional>

#include <engine/event/eventManager.hpp>
#include <engine/app/app.hpp>
#include <engine/sdl2app/sdl2App.hpp>

#include <application/events/demoEvent.hpp>
#include <application/observers/demoObserver.hpp>

#include <application/utils/constants.hpp>

/**
 * @brief Main Application class
 * Inherited from SDL2App. It is possible tho to create implementations using other rendering systems.
 * As long as the said implementation respects the interface of the main App.
 * SDL2App is the default app of this framework, for SDL2 is simple to use and to maintain, as it is both very high level,
 * and low level api by giving access directly to the OpenGL context (although it is only needed for experienced users)
 * See the documentation of the App.hpp Interface to learn more about Apps, and what they are and are not. 
 */
class MyApp : public SDL2App {
    public:
        MyApp(const int windowWidth, const int windowHeight, const char *windowName) : SDL2App(windowWidth, windowHeight, windowName) {}

        void Init() {
            // Call to Parent App method. Should never be removed in an inherited App
            SDL2App::Init();
        }

        void Update() {
            // Call to Parent App method. Should never be removed in an inherited App
            SDL2App::Update();
        }

        void Draw() {
            // Call to Parent App method. Should never be removed in an inherited App
            SDL2App::Draw();
        }

        void LateUpdate() {
            // Call to Parent App method. Should never be removed in an inherited App
            SDL2App::LateUpdate();
        }

        void Quit() {
            // Call to Parent App method. Should never be removed in an inherited App
            SDL2App::Quit();
        }
};

/**
 * @brief Main entry point of the app.
 * It contains a main loop that loads the MyApp App defined above.
 * You shouldn't be editing past this point really, until you REALLY know what you are doing.
 * 
 * End event the, you should be careful about the implementation of your App and the main loop, that's
 * probably the less flexible part of the whole framework. Most of the code should go directly in the above custom class
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]) {
    App *app = new MyApp(SCREEN_WIDTH, SCREEN_HEIGHT, APP_NAME);

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