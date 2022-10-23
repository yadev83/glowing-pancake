#include "demoEvent.hpp"

constexpr Event::EventID DemoEvent::id;
Event::EventID DemoEvent::type() const { return id; }