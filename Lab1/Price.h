#ifndef PRICE_H
#define PRICE_H

struct Price {
    int hryvnias;
    short kopecks;
};

Price createPrice(int h, short k);
Price addPrice(const Price& p1, const Price& p2);
Price multiplyPrice(const Price& p, int quantity);
void roundPrice(Price& p);
void printPrice(const Price& p);

#endif
