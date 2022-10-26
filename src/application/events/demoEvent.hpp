#ifndef EVENTS_DEMO_EVENT_H
#define EVENTS_DEMO_EVENT_H

#include <engine/event/event.hpp>

class DemoEvent : public Event {
    public:
        static constexpr EventID id = "DemoEvent";
        virtual EventID type() const;
};

#endif