#include "classes5.h"

// Реалізація класу Plant
Plant::Plant() : type(""), height(0), color("") {
    std::cout << "Конструктор Plant викликано." << std::endl;
}

Plant::~Plant() {
    std::cout << "Деструктор Plant викликано." << std::endl;
}

void Plant::SetType(const std::string& plant_type) {
    type = plant_type;
}

void Plant::SetHeight(int plant_height) {
    height = plant_height;
}

void Plant::SetColor(const std::string& plant_color) {
    color = plant_color;
}

void Plant::Describe() const {
    std::cout << "Це рослина." << std::endl;
}

void Plant::PrintInfo() const {
    std::cout << "Рослина: Тип: " << type << ", Висота: " << height << " см, Колір: " << color << "." << std::endl;
}

// Реалізація класу Flower
Flower::Flower() {
    SetType("Квітка");
    SetHeight(30);
    SetColor("фіолетовий");
    std::cout << "Конструктор Flower викликано." << std::endl;
}

Flower::~Flower() {
    std::cout << "Деструктор Flower викликано." << std::endl;
}

void Flower::Describe() const {
    std::cout << "Ця квітка неймовірна." << std::endl;
}

void Flower::PrintInfo() const {
    std::cout << "Квітка: Тип: " << type << ", Висота: " << height << " см, Колір: " << color << "." << std::endl;
}

// Реалізація класу Tree
Tree::Tree() {
    SetType("Дерево");
    SetHeight(500);
    SetColor("зелений");
    std::cout << "Конструктор Tree викликано." << std::endl;
}

Tree::~Tree() {
    std::cout << "Деструктор Tree викликано." << std::endl;
}

void Tree::Describe() const {
    std::cout << "Це дерево дуже високе." << std::endl;
}

void Tree::PrintInfo() const {
    std::cout << "Дерево: Тип: " << type << ", Висота: " << height << " см, Колір: " << color << "." << std::endl;
}

// Реалізація класу BlossomTree
BlossomTree::BlossomTree() {
    SetType("Квітуче дерево");
    SetHeight(400);
    SetColor("рожевий");
    std::cout << "Конструктор BlossomTree викликано." << std::endl;
}

BlossomTree::~BlossomTree() {
    std::cout << "Деструктор BlossomTree викликано." << std::endl;
}

void BlossomTree::Describe() const {
    std::cout << "Це квітуче дерево з красивими квітами." << std::endl;
}

void BlossomTree::PrintInfo() const {
    std::cout << "Квітуче дерево: Тип: " << type << ", Висота: " << height << " см, Колір: " << color << "." << std::endl;
}

// Реалізація класу HybridPlant
HybridPlant::HybridPlant(const std::string& name, const std::string& color, int height)
    : Plant(), Flower(), Tree(), BlossomTree() {
    hybridName = name;
    SetColor(color);
    SetHeight(height);
    std::cout << "Конструктор HybridPlant викликано." << std::endl;
}

HybridPlant::~HybridPlant() {
    std::cout << "Деструктор HybridPlant викликано." << std::endl;
}

void HybridPlant::Describe() const {
    std::cout << "Це гібридна рослина: " << hybridName << "." << std::endl;
}

void HybridPlant::PrintInfo() const {
    std::cout << "Гібридна рослина: Назва: " << hybridName
              << ", Висота: " << height
              << " см, Колір: " << color << "." << std::endl;
}
