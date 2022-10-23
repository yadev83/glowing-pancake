#include "event.hpp"
#include "eventManager.hpp"

#include <iostream>

void EventManager::subscribe(const Event::EventID& eventID, Action&& action) {
    _observers[eventID].push_back(action);
}

void EventManager::dispatch(const Event& event) const {
    // If the event type has no observers attached, ignore it
    if(_observers.find(event.type()) == _observers.end()) {
        return;
    }

    auto&& observers = _observers.at(event.type());

    for(auto&& observer: observers) {
        observer(event);
    }
}