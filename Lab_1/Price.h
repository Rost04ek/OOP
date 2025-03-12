#ifndef PRICE_H
#define PRICE_H

struct Price {
    int hryvnias;
    short kopecks;
};

void roundPrice(Price& p);
void printPrice(Price& p);
void AddPrice(Price& p1, Price& p2);

#endif
