#include <iostream>

#include "event.hpp"
#include "eventManager.hpp"

EventManager *EventManager::m_instance = nullptr;

EventManager *EventManager::get() {
    if(m_instance == nullptr) {
        m_instance = new EventManager();
    }

    return m_instance;
}

void EventManager::subscribe(const Event::EventID& eventID, Action&& action) {
    m_observers[eventID].push_back(action);
}

void EventManager::dispatch(const Event& event) const {
    // If the event type has no observers attached, ignore it
    if(m_observers.find(event.type()) == m_observers.end()) {
        return;
    }

    auto&& observers = m_observers.at(event.type());

    for(auto&& observer: observers) {
        observer(event);
    }
}