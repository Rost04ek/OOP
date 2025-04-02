#ifndef GEOMETRY_H
#define GEOMETRY_H

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
    
    double area() const;
    bool isPointOnSegment(const Point &P, const Point &start, const Point &end) const;
    bool isDegenerate() const;
    int checkPoint(const Point &P) const;
    int checkPointVector(const Point &P) const;
};

double vectorProduct(const Point &A, const Point &B, const Point &C);

#endif
