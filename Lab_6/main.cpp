#include "Lambda.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int choice;
    
    auto DisplayMenu = []() {
        std::cout << "1. Розв'язати квадратне рівняння\n";
        std::cout << "2. Розв'язати нелінійне рівняння (метод бісекції)\n";
        std::cout << "3. Демонстрація захоплення змінних у лямбда-виразах\n";
        std::cout << "4. Демонстрація типів повернення лямбда-виразів\n";
        std::cout << "0. Вихід\n";
        std::cout << "Введіть ваш вибір: ";
    };
    
    do {
        DisplayMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                LambdaExamples::solveQuadraticEquation();
                break;
            case 2:
                LambdaExamples::solveNonlinearEquation();
                break;
            case 3:
                LambdaExamples::demonstrateLambdaCapture();
                break;
            case 4:
                LambdaExamples::demonstrateLambdaReturnTypes();
                break;
            default:
                std::cout << "ERROR 404! Давай до початку.\n";
        }
    } while (choice != 0);

    return 0;
}