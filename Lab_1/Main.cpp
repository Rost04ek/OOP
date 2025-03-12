#include <iostream>
#include <fstream>
#include "Price.h"

int main() {
    std::ifstream file("prices.txt");
    if (!file) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }

    int hryvnias, quantity;
    short int kopecks;
    Price total = {0, 0};

    while (file >> hryvnias >> kopecks >> quantity) {
        Price itemPrice = {hryvnias, kopecks};
        int totalKopecks = (itemPrice.hryvnias * 100 + itemPrice.kopecks) * quantity;
        Price totalItemPrice = {totalKopecks / 100, (totalKopecks % 100)};
        AddPrice(total, totalItemPrice);
    }

    std::cout << "Suma: ";
    printPrice(total);

    roundPrice(total);
    std::cout << "Zaokruglena Suma: ";
    printPrice(total);

    return 0;
}
