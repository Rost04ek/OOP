#include "geometry.h"
#include <cmath>

double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double vectorProduct(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

double Triangle::area() const {
    double a = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    double b = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
    double c = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2));
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool Triangle::isPointOnSegment(const Point &P, const Point &start, const Point &end) const {
    double d1 = sqrt(pow(P.x - start.x, 2) + pow(P.y - start.y, 2));
    double d2 = sqrt(pow(P.x - end.x, 2) + pow(P.y - end.y, 2));
    double d3 = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
    return fabs(d1 + d2 - d3) < 1e-9;
}

bool Triangle::isDegenerate() const {
    return fabs(area()) < 1e-9;
}

int Triangle::checkPoint(const Point &P) const {
    if (isPointOnSegment(P, A, B) || 
        isPointOnSegment(P, B, C) || 
        isPointOnSegment(P, C, A)) {
        return 1;
    }

    Triangle T1 = {A, B, P};
    Triangle T2 = {B, C, P};
    Triangle T3 = {C, A, P};

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();
    
    if (fabs(S_main - S_sum) < 1e-9) {
        return 2;
    }
    
    return 0;
}

int Triangle::checkPointVector(const Point &P) const {
    double v1 = vectorProduct(A, B, P);
    double v2 = vectorProduct(B, C, P);
    double v3 = vectorProduct(C, A, P);
    
    if (fabs(v1) < 1e-9 || fabs(v2) < 1e-9 || fabs(v3) < 1e-9) {
        if (isPointOnSegment(P, A, B) || 
            isPointOnSegment(P, B, C) || 
            isPointOnSegment(P, C, A)) {
            return 1;
        }
    }
    
    bool allPositive = (v1 >= 0 && v2 >= 0 && v3 >= 0);
    bool allNegative = (v1 <= 0 && v2 <= 0 && v3 <= 0);
    
    if (allPositive || allNegative) {
        return 2;
    }
    
    return 0;
}

double heronArea(const Triangle &t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
