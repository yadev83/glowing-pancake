#ifndef EVENT_EVENT_H
#define EVENT_EVENT_H

/**
 * @brief Event class
 * 
 * An event has a unique identifier (used to subscribe)
 * 
 */
class Event {
    public:
        Event() = default;
        virtual ~Event() = default;

        using EventID = const char *;
        virtual EventID type() const = 0;
};

#endif