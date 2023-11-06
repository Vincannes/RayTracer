#include <cmath>
#include <iomanip>
#include <iostream>

#include "mn_color.h"

Color::Color() noexcept : Vector(0.0f, 0.0f, 0.0f) {}

Color::Color(float x, float y, float z) noexcept : Vector(x, y, z) {}

Color Color::operator+(const Color& other) const {
        Color result;
        result.x = x * other.x;
        result.y = y * other.y;
        result.z = z * other.z;
        return result;
}

Color& Color::operator+=(const Color& other) {
    x += other.x;
    y += other.z;
    z += other.z;
    return *this;
}

Color Color::operator*(float color) const {
        Color result;
        result.x = x * color;
        result.y = y * color;
        result.z = z * color;
        return result;
}

Color Color::fromHex(std::string hexcolor)
{
    if (hexcolor.length() != 7 || hexcolor[0] != '#') {
        // Gérer les erreurs si la chaîne n'est pas au bon format
        return Color(); // Utilisez le constructeur par défaut pour initialiser à (0.0f, 0.0f, 0.0f)
    }

    int r_hex = std::stoi(hexcolor.substr(1, 2), nullptr, 16);
    int g_hex = std::stoi(hexcolor.substr(3, 2), nullptr, 16);
    int b_hex = std::stoi(hexcolor.substr(5, 2), nullptr, 16);

    float r = static_cast<float>(r_hex) / 255.0f;
    float g = static_cast<float>(g_hex) / 255.0f;
    float b = static_cast<float>(b_hex) / 255.0f;

    Color result;
    result.x = r;
    result.y = g;
    result.z = b;

    return result;
}
