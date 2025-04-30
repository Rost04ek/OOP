#include "classes.h"

// Реалізація класу Plant
Plant::Plant() : type(""), height(0), color("") {}

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

// Реалізація класу FruitTree
FruitTree::FruitTree(const std::string& fruit_type) : fruitType(fruit_type) {
    SetType("Фруктове дерево");
    std::cout << "Конструктор FruitTree викликано." << std::endl;
}

FruitTree::FruitTree() : fruitType("") {
}

FruitTree::~FruitTree() {
    std::cout << "Деструктор FruitTree викликано." << std::endl;
}

void FruitTree::SetFruitType(const std::string& fruit_type) {
    fruitType = fruit_type;
}

void FruitTree::PrintInfo() const {
    std::cout << "Фруктове дерево: Тип: " << type << ", Висота: " << height << " см, Колір: " << color << ", Фрукти: " << fruitType << "." << std::endl;
}

// Реалізація класу HomePlant
HomePlant::HomePlant(const std::string& fruit_type, const std::string& plant_name, const std::string& plant_location) {
    SetFruitType(fruit_type);
    SetName(plant_name);
    SetLocation(plant_location);
    std::cout << "Конструктор HomePlant викликано." << std::endl;
}

HomePlant::~HomePlant() {
    std::cout << "Деструктор HomePlant викликано." << std::endl;
}

void HomePlant::SetName(const std::string& plant_name) {
    name = plant_name;
}

void HomePlant::SetLocation(const std::string& plant_location) {
    location = plant_location;
}

void HomePlant::PrintInfo() const {
    std::cout << "Домашня рослина: Ім'я: " << name << ", Місце: " << location << ", Тип: " << type << ", Висота: " << height << " см, Колір: " << color << ", Фрукти: " << fruitType << "." << std::endl;
}