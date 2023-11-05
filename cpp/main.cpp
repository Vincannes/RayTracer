#include <string>
#include <iostream>

#include "include/mn_vector.h"
#include "include/mn_point.h"
#include "include/mn_color.h"
#include "include/mn_materials.h"

int main() {
    std::cout << "" << std::endl;

    Vector camera(1, -2, -2);
    Vector v2(3, 6, 8);

    PositionPoint p1(2, 3, 5);
    Color white = Color::fromHex("#420500");

    std::cout << camera.doProduct(v2) << std::endl;
    std::cout << camera.magnitude() << std::endl;
    std::cout << camera.normalize().x << " " << camera.normalize().y<< " " << camera.normalize().z << std::endl;

    std::cout << p1.x << std::endl;
    std::cout << "color  " << white.x << std::endl;

    Material material(Color::fromHex("#FFFFFF"), 0.05f, 1.0f, 1.0f, 0.5f);
    std::cout << "materiale  " << material.color.y << std::endl;

    return 1;
}
