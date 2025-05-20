#include <iostream>
#include "Bridge.h"
#include "Builder.h"

int main() {
    // Bridge
    std::cout << "=== Bridge Pattern ===" << std::endl;
    TV tv;
    Radio radio;
    SimpleRemote simpleRemote(&tv);
    AdvancedRemote advancedRemote(&radio);
    simpleRemote.ButtonPress();
    advancedRemote.ButtonPress();

    // Builder
    std::cout << "\n=== Builder Pattern ===" << std::endl;
    MargheritaBuilder margherita;
    Chef chef1(&margherita);
    chef1.MakePizza();
    Pizza* pizza1 = margherita.GetPizza();
    pizza1->Show();
    delete pizza1;

    PepperoniBuilder pepperoni;
    Chef chef2(&pepperoni);
    chef2.MakePizza();
    Pizza* pizza2 = pepperoni.GetPizza();
    pizza2->Show();
    delete pizza2;

    return 0;
}