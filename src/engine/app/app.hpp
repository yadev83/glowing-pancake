// Will contain a generic app code
// SDL2 should be implementing this in application/SDL2App
#ifndef APP_EVENT_H
#define APP_EVENT_H

#include <functional>

#include <utils/event/eventManager.hpp>

class App {
    protected:
        bool m_quit = false;

    public:
        App();
        bool shouldQuit();

        virtual bool ready() = 0;
        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual void LateUpdate() = 0;
        virtual void Quit() = 0;
};

#endif