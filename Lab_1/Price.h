#ifndef PRICE_H
#define PRICE_H

struct Price {
    int hryvnias;
    short kopecks;
};

void roundPrice(Price& p);
void printPrice(const Price& p);
void AddPrice(Price& p1, const Price& p2);

#endif
