#include <iomanip>
#include <iostream>

#include "mn_color.h"

Color::Color(float x, float y, float z) noexcept : Vector(x, y, z)
{
    
}

Color Color::fromHex(std::string hexcolor)
{
    float x, y, z;
     if (hexcolor.length() != 7 || hexcolor[0] != '#') {
        std::cerr << "Invalid hexcolor format." << std::endl;
        return Color(0.0f, 0.0f, 0.0f);
    }

    int red = std::stoi(hexcolor.substr(1, 2), 0, 16);
    int green = std::stoi(hexcolor.substr(3, 2), 0, 16);
    int blue = std::stoi(hexcolor.substr(5, 2), 0, 16);

    float r = static_cast<float>(red) / 255.0f;
    float g = static_cast<float>(green) / 255.0f;
    float b = static_cast<float>(blue) / 255.0f;

    return Color(r, g, b);
}
