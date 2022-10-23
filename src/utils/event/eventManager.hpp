#ifndef EVENT_EVENT_MANAGER_H
#define EVENT_EVENT_MANAGER_H

#include <functional>
#include <map>
#include <vector>

#include "event.hpp"

class EventManager {
    public:
        using Action = std::function< void(const Event&) >;
    
    
        void subscribe(const Event::EventID& eventID, Action&& action);
        void dispatch(const Event& event) const;

    private:
        std::map<Event::EventID, std::vector<Action>> _observers;
};

#endif