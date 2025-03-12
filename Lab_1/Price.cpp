#include <iostream>
#include "Price.h"

void roundPrice(Price& p) {
    if (p.kopecks % 10 >= 5) {
        p.kopecks += 10 - (p.kopecks % 10);
    } else {
        p.kopecks -= p.kopecks % 10;
    }
    if (p.kopecks >= 100) {
        p.hryvnias += p.kopecks / 100;
        p.kopecks %= 100;
    }
}

void printPrice(const Price& p) {
    std::cout << p.hryvnias << " UAH " << p.kopecks << " kopecks" << std::endl;
}

void AddPrice(Price& p1, const Price& p2) {
    p1.hryvnias += p2.hryvnias;
    p1.kopecks += p2.kopecks;
    if (p1.kopecks >= 100) {
        p1.hryvnias += p1.kopecks / 100;
        p1.kopecks %= 100;
    }
    printPrice(p1);
}
