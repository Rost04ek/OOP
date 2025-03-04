#include <iostream>
#include "Price.h"

Price createPrice(int h, short k) {
    Price p;
    p.hryvnias = h;
    p.kopecks = k;
    return p;
}

Price addPrice(const Price& p1, const Price& p2) {
    int totalKopecks = p1.kopecks + p2.kopecks;
    int totalHryvnias = p1.hryvnias + p2.hryvnias + totalKopecks / 100;
    totalKopecks %= 100;
    return createPrice(totalHryvnias, totalKopecks);
}

Price multiplyPrice(const Price& p, int quantity) {
    int totalKopecks = (p.hryvnias * 100 + p.kopecks) * quantity;
    int totalHryvnias = totalKopecks / 100;
    totalKopecks %= 100;
    return createPrice(totalHryvnias, totalKopecks);
}

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
