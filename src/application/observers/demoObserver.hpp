#ifndef OBSERVERS_DEMO_OBSERVER_HPP
#define OBSERVERS_DEMO_OBSERVER_HPP

#include <iostream>

#include <utils/event/event.hpp>

class DemoObserver {
    public:
        void onDemoEvent(const Event& e);
};

#endif