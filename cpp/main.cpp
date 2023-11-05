#include <string>
#include <iostream>

#include "include/mn_vector.h"
#include "include/mn_point.h"
#include "include/mn_color.h"

int main() {
    std::cout << "" << std::endl;

    Vector camera(1, -2, -2);
    Vector v2(3, 6, 8);

    PositionPoint p1(2, 3, 5);

    std::cout << camera.doProduct(v2) << std::endl;
    std::cout << camera.magnitude() << std::endl;
    std::cout << camera.normalize().x << " " << camera.normalize().y<< " " << camera.normalize().z << std::endl;

    std::cout << p1.x << std::endl;
    std::cout << "color  " << Color::fromHex("#420500").x << std::endl;

    return 1;
}
