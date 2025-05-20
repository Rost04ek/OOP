#pragma once
#include <vector>
#include <string>

class Pizza {
    std::vector<std::string> ingredients;
public:
    void AddIngredient(const std::string& ing);
    void Show() const;
};

class PizzaBuilder {
public:
    virtual ~PizzaBuilder() {}
    virtual void AddDough() = 0;
    virtual void AddSauce() = 0;
    virtual void AddTopping() = 0;
    virtual Pizza* GetPizza() = 0;
};

class MargheritaBuilder : public PizzaBuilder {
    Pizza* pizza;
public:
    MargheritaBuilder();
    ~MargheritaBuilder() override;
    void AddDough() override;
    void AddSauce() override;
    void AddTopping() override;
    Pizza* GetPizza() override;
};

class PepperoniBuilder : public PizzaBuilder {
    Pizza* pizza;
public:
    PepperoniBuilder();
    ~PepperoniBuilder() override;
    void AddDough() override;
    void AddSauce() override;
    void AddTopping() override;
    Pizza* GetPizza() override;
};

class Chef {
    PizzaBuilder* builder;
public:
    Chef(PizzaBuilder* b);
    void MakePizza();
};