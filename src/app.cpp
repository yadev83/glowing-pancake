#include <iostream>
#include <functional>

#include <utils/event/eventManager.hpp>

#include <application/events/demoEvent.hpp>
#include <application/observers/demoObserver.hpp>

using namespace std::placeholders;


int main(int argc, char *argv[]) {
    EventManager *eventManager = EventManager::get();
    DemoObserver observer;

    eventManager->subscribe(DemoEvent::id, std::bind(&DemoObserver::onDemoEvent, observer, _1));
    eventManager->dispatch(DemoEvent());

    return 0;
}