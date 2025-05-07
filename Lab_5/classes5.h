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

class Flower : public virtual Plant {
public:
    Flower();
    virtual ~Flower();
    void Describe() const override;
    void PrintInfo() const override;
};

class Tree : public virtual Plant {
public:
    Tree();
    virtual ~Tree();
    void Describe() const override;
    void PrintInfo() const override;
};

class FruitTree : public virtual Tree {
protected:
    std::string fruitType;

public:
    FruitTree(const std::string& fruit_type);
    FruitTree();
    virtual ~FruitTree();
    void SetFruitType(const std::string& fruit_type);
    void PrintInfo() const override;
};

class HybridPlant : public virtual Flower, public virtual FruitTree {
private:
    std::string hybridName;

public:
    HybridPlant(const std::string& name, const std::string& fruitType, const std::string& color);
    virtual ~HybridPlant();
    void Describe() const override;
    void PrintInfo() const override;
};