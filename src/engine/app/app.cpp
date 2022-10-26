#include "app.hpp"

App::App() {
    m_eventManager = EventManager::get();
}

bool App::shouldQuit() { return m_quit; }