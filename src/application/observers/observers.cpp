#include "demoObserver.hpp"

void DemoObserver::onDemoEvent(const Event& e) {
    std::cout << "Demo event fired, this is a demo handler !" << std::endl;
}