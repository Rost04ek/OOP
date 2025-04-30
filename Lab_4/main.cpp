#include "classes.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // Домашня рослина
    std::cout << "=== Створення об'єкта HomePlant ===" << std::endl;
    HomePlant* my_plant = new HomePlant("Банани", "Георгій", "посадка");
    my_plant->PrintInfo();
    delete my_plant;
    std::cout << "=== Видалення об'єкта HomePlant ===\n" << std::endl;

    // Квітка
    std::cout << "=== Створення об'єкта Flower ===" << std::endl;
    Flower* my_flower = new Flower();
    my_flower->PrintInfo();
    delete my_flower;
    std::cout << "=== Видалення об'єкта Flower ===\n" << std::endl;

    // Дерево
    std::cout << "=== Створення об'єкта Tree ===" << std::endl;
    Tree* my_tree = new Tree();
    my_tree->PrintInfo();
    delete my_tree;
    std::cout << "=== Видалення об'єкта Tree ===\n" << std::endl;

    // Фруктове дерево
    std::cout << "=== Створення об'єкта FruitTree ===" << std::endl;
    FruitTree* my_fruit_tree = new FruitTree("Апельсини");
    my_fruit_tree->PrintInfo();
    delete my_fruit_tree;
    std::cout << "=== Видалення об'єкта FruitTree ===\n" << std::endl;

    return 0;
}