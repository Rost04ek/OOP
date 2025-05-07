#pragma once
#include <iostream>
#include <cmath>
#include <functional>
#include <iomanip>

namespace LambdaExamples {
    using EquationFunction = std::function<double(double)>;

    void solveQuadraticEquation();
    double bisectionMethod(const EquationFunction& f, double a, double b, double epsilon, int maxIterations);
    void solveNonlinearEquation();
    void demonstrateLambdaCapture();
    void demonstrateLambdaReturnTypes();
}