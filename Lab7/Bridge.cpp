#include "Bridge.h"
#include <iostream>

std::string TV::Operation() const {
    return "TV is ON";
}

std::string Radio::Operation() const {
    return "Radio is PLAYING";
}

Remote::Remote(Device* d) : device(d) {}

SimpleRemote::SimpleRemote(Device* d) : Remote(d) {}

void SimpleRemote::ButtonPress() const {
    std::cout << "SimpleRemote: " << device->Operation() << std::endl;
}

AdvancedRemote::AdvancedRemote(Device* d) : Remote(d) {}

void AdvancedRemote::ButtonPress() const {
    std::cout << "AdvancedRemote: " << device->Operation() << " with extra features" << std::endl;
}