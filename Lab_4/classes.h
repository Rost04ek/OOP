#pragma once
#include <iostream>
#include <string>

class Plant {
protected:
    std::string type;
    int height;
    std::string color;

public:
    Plant();
    virtual ~Plant();
    void SetType(const std::string& plant_type);
    void SetHeight(int plant_height);
    void SetColor(const std::string& plant_color);
    virtual void Describe() const;
    virtual void PrintInfo() const;
};

class Flower : public Plant {
public:
    Flower();
    virtual ~Flower(); 
    void Describe() const override;
    void PrintInfo() const override;
};

class Tree : public Plant {
public:
    Tree();
    virtual ~Tree();
    void Describe() const override;
    void PrintInfo() const override;
};

class FruitTree : public Tree {
protected:
    std::string fruitType;

public:
    FruitTree(const std::string& fruit_type);
    FruitTree();
    virtual ~FruitTree(); 
    void SetFruitType(const std::string& fruit_type);
    void PrintInfo() const override;
};

class HomePlant : public FruitTree {
private:
    std::string name;
    std::string location;

public:
    HomePlant(const std::string& fruit_type, const std::string& plant_name, const std::string& plant_location);
    virtual ~HomePlant();
    void SetName(const std::string& plant_name);
    void SetLocation(const std::string& plant_location);
    void PrintInfo() const override;
};