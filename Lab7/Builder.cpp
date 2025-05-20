#include "Builder.h"
#include <iostream>

// --- Pizza ---
void Pizza::AddIngredient(const std::string& ing) {
    ingredients.push_back(ing);
}
void Pizza::Show() const {
    std::cout << "Pizza with: ";
    for (const auto& ing : ingredients) std::cout << ing << " ";
    std::cout << std::endl;
}

// --- MargheritaBuilder ---
MargheritaBuilder::MargheritaBuilder() { pizza = new Pizza(); }
MargheritaBuilder::~MargheritaBuilder() { delete pizza; }
void MargheritaBuilder::AddDough() { pizza->AddIngredient("Thin Dough"); }
void MargheritaBuilder::AddSauce() { pizza->AddIngredient("Tomato Sauce"); }
void MargheritaBuilder::AddTopping() { pizza->AddIngredient("Mozzarella"); }
Pizza* MargheritaBuilder::GetPizza() {
    Pizza* result = pizza;
    pizza = nullptr;
    return result;
}

// --- PepperoniBuilder ---
PepperoniBuilder::PepperoniBuilder() { pizza = new Pizza(); }
PepperoniBuilder::~PepperoniBuilder() { delete pizza; }
void PepperoniBuilder::AddDough() { pizza->AddIngredient("Thick Dough"); }
void PepperoniBuilder::AddSauce() { pizza->AddIngredient("Spicy Sauce"); }
void PepperoniBuilder::AddTopping() { pizza->AddIngredient("Pepperoni"); }
Pizza* PepperoniBuilder::GetPizza() {
    Pizza* result = pizza;
    pizza = nullptr;
    return result;
}

// --- Chef ---
Chef::Chef(PizzaBuilder* b) : builder(b) {}
void Chef::MakePizza() {
    builder->AddDough();
    builder->AddSauce();
    builder->AddTopping();
}