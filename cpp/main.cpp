#include <iostream>

#include "include/mn_vector.h"

int main() {
    std::cout << "" << std::endl;

    Vector v1(1, -2, -2);
    Vector v2(3, 6, 8);

    std::cout << v1.doProduct(v2) << std::endl;
    return 1;
}
