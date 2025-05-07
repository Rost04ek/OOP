#include "classes5.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    std::cout << "=== Створення об'єкта HybridPlant ===" << std::endl;
    HybridPlant my_hybrid("Гібридус", "Фіолетовий", 350);
    my_hybrid.PrintInfo();
    my_hybrid.Describe();
    std::cout << "=== Видалення об'єкта HybridPlant ===" << std::endl;

    return 0;
}
