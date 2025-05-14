#pragma once

class RKClass 
{
private:
    double x;
    double x1;
    double a, b, eps;

public: 
    RKClass();
    ~RKClass();

    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);

    double f(double x);
    double df(double x);

    int dixotomia(double &x); 
    int newton(double x0, double &x);
};