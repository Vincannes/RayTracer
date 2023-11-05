#include <string>

#include <mn_vector.h>

#ifndef MN_COLOR_H
#define MN_COLOR_H

class Color {
/*Stores color as RGB triplets. An alias for Vector.*/

public:
    float r, g, b;
    Color(float red, float green, float blue) : r(red), g(green), b(blue) {}

    static Vector fromHex(std::string hexcolor);

private:

};


#endif