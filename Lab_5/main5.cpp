#include "classes5.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    std::cout << "=== Створення об'єкта HybridPlant ===" << std::endl;
    HybridPlant* my_hybrid = new HybridPlant("Гібридус", "Фіолетовий", 350);
    my_hybrid->PrintInfo();
    my_hybrid->Describe();
    std::cout << "=== Видалення об'єкта Hybridplant ===" << std::endl;
    delete my_hybrid;

    std::cout << "=== Створення об'єкта MegaPlant ===" << std::endl;
    MegaPlant* my_mega_plant = new MegaPlant();
    my_mega_plant->PrintInfo();
    my_mega_plant->Describe();
    std::cout << "=== Видалення об'єкта Megaplant ===" << std::endl;
    delete my_mega_plant;

    return 0;
}
