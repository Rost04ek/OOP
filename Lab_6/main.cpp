#include <iostream>
#include "Lambda.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    RKClass solver;
    solver.setVolumes(0.4, 1.0);
    solver.setTolerance(1e-6);

    std::cout << "Оберіть метод:\n1 - Метод Дихотомії\n2 - Метод Ньютона\nВаш вибір: ";
    int choice;
    std::cin >> choice;

    double x;
    if (choice == 1) {
        if (solver.dixotomia(x) == 0) {
            std::cout << "Корінь рівняння (метод дихотомії): " << x << std::endl;
            std::cout << "Перевірка: f(x) = " << solver.f(x) << std::endl;
        }
    } else if (choice == 2) {
        double x0 = 0.5;
        if (solver.newton(x0, x) == 0) {
            std::cout << "Корінь рівняння (метод Ньютона): " << x << std::endl;
            std::cout << "Перевірка: f(x) = " << solver.f(x) << std::endl;
        }
    } else {
        std::cout << "Невірний вибір методу!" << std::endl;
    }

    return 0;
}