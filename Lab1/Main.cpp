#include <iostream>
#include <fstream>
#include "Price.h"

int main() {
    std::ifstream file("prices.txt");
    if (!file) {
        std::cerr << "File ERROR!" << std::endl;
        return 1;
    }

    int hryvnias, kopecks, quantity;
    Price total = createPrice(0, 0);

    while (file >> hryvnias >> kopecks >> quantity) {
        Price itemPrice = createPrice(hryvnias, kopecks);
        Price totalItemPrice = multiplyPrice(itemPrice, quantity);
        total = addPrice(total, totalItemPrice);
    }

    std::cout << "Suma: ";
    printPrice(total);

    roundPrice(total);
    std::cout << "Zaokruglena Suma: ";
    printPrice(total);

    return 0;
}
