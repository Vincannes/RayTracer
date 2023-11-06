#include <string>

#include <mn_vector.h>

#ifndef MN_COLOR_H
#define MN_COLOR_H

class Color : public Vector {
public:
    Color() noexcept,
    Color(float x, float y, float z) noexcept;
    Color operator+(const Color& other) const;
    Color& operator+=(const Color& other);
    Color operator*(float color) const;
    static Color fromHex(std::string hexcolor);
};


#endif
