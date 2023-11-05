#include <string>

#include <mn_vector.h>

#ifndef MN_COLOR_H
#define MN_COLOR_H

class Color : public Vector
{
/*Stores color as RGB triplets. An alias for Vector.*/

public:

    Color(float x, float y, float z) noexcept;
    static Color fromHex(std::string hexcolor);

private:

};


#endif