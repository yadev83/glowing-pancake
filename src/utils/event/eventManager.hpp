#ifndef EVENT_EVENT_MANAGER_H
#define EVENT_EVENT_MANAGER_H

#include <functional>
#include <map>
#include <vector>

#include "event.hpp"

class EventManager {
    protected:
        EventManager() {}
        static EventManager *m_instance;
    public:
        EventManager(EventManager &other) = delete;
        void operator=(const EventManager &) = delete;
        static EventManager *get();

        using Action = std::function< void(const Event&) >;
    
        void subscribe(const Event::EventID& eventID, Action&& action);
        void dispatch(const Event& event) const;

    private:
        std::map<Event::EventID, std::vector<Action>> m_observers;
};

#endif