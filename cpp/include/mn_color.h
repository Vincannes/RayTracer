#include <string>

#include <mn_vector.h>

#ifndef MN_COLOR_H
#define MN_COLOR_H

class Color : public Vector {
public:
    Color() : Vector(0.0f, 0.0f, 0.0f) {} // Constructeur par défaut initialisant à du noir (0, 0, 0)
    Color(float x, float y, float z) noexcept;
    static Color fromHex(std::string hexcolor);
};

#endif
