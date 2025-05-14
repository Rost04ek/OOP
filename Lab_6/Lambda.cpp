#include "Lambda.h"
#include <cmath>
#include <iostream>

RKClass::RKClass() : x(0), x1(0), a(0.4), b(1.0), eps(1e-6) {}

RKClass::~RKClass() {}

void RKClass::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void RKClass::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double RKClass::f(double x) {
    return x + std::pow(x, 0.5) + std::pow(x, 1.0/3) - 2.5;
}

double RKClass::df(double x) {
    double dx = 1e-8;
    return (f(x + dx) - f(x)) / dx;
}

int RKClass::dixotomia(double &x) {
    auto isRootInInterval = [this](double a, double b) {
        return f(a) * f(b) <= 0;
    };

    if (!isRootInInterval(a, b)) {
        std::cout << "На проміжку [" << a << "; " << b << "] немає кореня або їх парна кількість.\n";
        return -1;
    }

    double c;
    double a_local = a, b_local = b;
    while ((b_local - a_local) > eps) {
        c = (a_local + b_local) / 2.0;
        if (isRootInInterval(a_local, c))
            b_local = c;
        else
            a_local = c;
    }

    x = (a_local + b_local) / 2.0;
    return 0;
}

int RKClass::newton(double x0, double &x) {
    int max_iter = 1000;
    int iter = 0;

    auto isConverged = [this](double x1, double x0) {
        return std::fabs(x1 - x0) < eps;
    };

    while (iter < max_iter) {
        double f_val = f(x0);
        double df_val = df(x0);

        if (fabs(df_val) < 1e-12) {
            std::cout << "Похідна близька до нуля. Метод Ньютона не може бути застосований.\n";
            return -1;
        }

        double x1 = x0 - f_val / df_val;

        if (isConverged(x1, x0)) {
            x = x1;
            return 0;
        }

        x0 = x1;
        iter++;
    }

    std::cout << "Перевищено максимальну кількість ітерацій у методі Ньютона.\n";
    return -1;
}