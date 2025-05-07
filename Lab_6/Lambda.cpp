#include "Lambda.h"

namespace LambdaExamples {

    void solveQuadraticEquation() {
        // Лямбда-вираз для обчислення дискримінанту
        auto discriminant = [](double a, double b, double c) -> double {
            return b * b - 4 * a * c;
        };

        double a, b, c;
        std::cout << "Введіть коефіцієнти квадратного рівняння (a, b, c): ";
        std::cin >> a >> b >> c;
        
        std::cout << "Рівняння: " << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
        
        [a, b, c, &discriminant]() {
            if (a == 0) {
                // Лямбда-вираз для лінійного рівняння
                [b, c]() {
                    if (b == 0) {
                        if (c == 0) {
                            std::cout << "Безліч розв'язків (тотожність)" << std::endl;
                        } else {
                            std::cout << "Немає розв'язків" << std::endl;
                        }
                        return;
                    }
                    std::cout << "Лінійне рівняння, розв'язок: x = " << -c / b << std::endl;
                }();
            } else {
                // Лямбда-вираз для квадратного рівняння
                [a, b, c, &discriminant]() {
                    double d = discriminant(a, b, c);
                    
                    if (d < 0) {
                        std::cout << "Немає дійсних розв'язків" << std::endl;
                    } else if (d == 0) {
                        double x = -b / (2 * a);
                        std::cout << "Один розв'язок: x = " << x << std::endl;
                    } else {
                        double x1 = (-b + std::sqrt(d)) / (2 * a);
                        double x2 = (-b - std::sqrt(d)) / (2 * a);
                        std::cout << "Два розв'язки: x1 = " << x1 << ", x2 = " << x2 << std::endl;
                    }
                }();
            }
        }();
    }

    double bisectionMethod(const EquationFunction& f, double a, double b, 
                          double epsilon, int maxIterations) {
        // Лямбда-вираз для перевірки точності
        auto isAccurateSolution = [](double x1, double x2, double epsilon) -> bool {
            return std::fabs(x2 - x1) < epsilon;
        };

        auto printIteration = [](int iter, double a, double b, double c, double fc) {
            std::cout << std::setw(4) << iter << " | "
                      << std::setw(10) << a << " | "
                      << std::setw(10) << b << " | "
                      << std::setw(10) << c << " | "
                      << std::setw(10) << fc << std::endl;
        };

        if (f(a) * f(b) > 0) {
            std::cout << "Функція не змінює знак на відрізку [" << a << ", " << b << "]" << std::endl;
            return NAN;
        }

        double c = a;
        int iteration = 0;

        std::cout << "Ітер |     a      |     b      |     c      |    f(c)    " << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;

        while (iteration < maxIterations && !isAccurateSolution(a, b, epsilon)) {
            c = (a + b) / 2;
            double fc = f(c);
            
            printIteration(iteration, a, b, c, fc);
            
            if (std::fabs(fc) < epsilon) {
                break;
            }

            if (f(a) * fc < 0) {
                b = c;
            } else {
                a = c;
            }
            
            iteration++;
        }

        return c;
    }

    void solveNonlinearEquation() {
        std::cout << "\n--- Розв'язування нелінійного рівняння ---\n";
        std::cout << "Оберіть тип рівняння:" << std::endl;
        std::cout << "1. x^3 - 5x + 1 = 0" << std::endl;
        std::cout << "2. sin(x) - 0.5 = 0" << std::endl;
        std::cout << "3. e^x - 3x = 0" << std::endl;
        std::cout << "Ваш вибір: ";
        
        int equationChoice;
        std::cin >> equationChoice;
        
        EquationFunction equation;
        double a, b;
        std::string equationStr;
        
        switch(equationChoice) {
            case 1:
                equation = [](double x) { return x*x*x - 5*x + 1; };
                equationStr = "x^3 - 5x + 1 = 0";
                a = -3.0;
                b = 3.0;
                break;
            case 2:
                equation = [](double x) { return std::sin(x) - 0.5; };
                equationStr = "sin(x) - 0.5 = 0";
                a = 0.0;
                b = 2.0;
                break;
            case 3:
                equation = [](double x) { return std::exp(x) - 3*x; };
                equationStr = "e^x - 3x = 0";
                a = 0.0;
                b = 2.0;
                break;
            default:
                std::cout << "Невірний вибір" << std::endl;
                return;
        }
        
        double epsilon = 0.0001;
        int maxIterations = 100;

        std::cout << "Розв'язання рівняння " << equationStr << " методом бісекції" << std::endl;
        std::cout << "Початковий відрізок: [" << a << ", " << b << "]" << std::endl;
        
        double solution = bisectionMethod(equation, a, b, epsilon, maxIterations);
        
        if (!std::isnan(solution)) {
            std::cout << "\nРозв'язок: x = " << solution << std::endl;
            std::cout << "Перевірка - f(" << solution << ") = " << equation(solution) << std::endl;
        }
    }

    void demonstrateLambdaCapture() {
        std::cout << "\n--- Демонстрація захоплення змінних у лямбда-виразах ---\n";
        
        int x = 10;
        int y = 20;
        
        std::cout << "Початкові значення: x = " << x << ", y = " << y << std::endl;
        
        // Лямбда-вираз з різними способами захоплення
        [&x, y]() mutable {
            x++; 
            y++;
            std::cout << "Усередині лямбда: x = " << x << ", y = " << y << std::endl;
        }();
        
        std::cout << "Після лямбда: x = " << x << ", y = " << y << std::endl;
        
        std::cout << "\nЩе приклади захоплення:\n";
        
        int a = 1, b = 2, c = 3;
        
        [=]() {
            std::cout << "Захоплення всіх за значенням: a = " << a << ", b = " << b << ", c = " << c << std::endl;
        }();
        
        [&]() {
            a += 10; b += 10; c += 10;
            std::cout << "Захоплення всіх за посиланням (після зміни): a = " << a << ", b = " << b << ", c = " << c << std::endl;
        }();
        
        // Змішане захоплення
        [=, &b]() {
            b += 5;
            std::cout << "Змішане захоплення (a і c за значенням, b за посиланням): a = " << a << ", b = " << b << ", c = " << c << std::endl;
        }();
        
        std::cout << "Кінцеві значення: a = " << a << ", b = " << b << ", c = " << c << std::endl;
    }

    void demonstrateLambdaReturnTypes() {
        std::cout << "\n--- Демонстрація типів повернення у лямбда-виразах ---\n";
        
        // Лямбда-вираз з неявним типом повернення
        auto implicitReturn = [](int x) {
            return x * 2;
        };
        
        // Лямбда-вираз з явним типом повернення
        auto explicitReturn = [](int x) -> double {
            return x * 2.5;
        };
        
        // Лямбда-вираз з умовним поверненням (один тип)
        auto conditionalReturn = [](int x) {
            if (x > 0) {
                return x * 2;
            } else {
                return x * -1;
            }
        };
        
        std::cout << "Неявне повернення: " << implicitReturn(5) << std::endl;
        std::cout << "Явне повернення: " << explicitReturn(5) << std::endl;
        std::cout << "Умовне повернення (додатне): " << conditionalReturn(5) << std::endl;
        std::cout << "Умовне повернення (від'ємне): " << conditionalReturn(-5) << std::endl;
        
        auto genericReturn = [](auto x, auto y) {
            return x + y;
        };
        
        std::cout << "Універсальне повернення з цілими: " << genericReturn(5, 10) << std::endl;
        std::cout << "Універсальне повернення з дійсними: " << genericReturn(5.5, 10.3) << std::endl;
        std::cout << "Універсальне повернення змішані типи: " << genericReturn(5, 10.5) << std::endl;
    }
}