#include <tuple>

#ifndef MN_VECTOR_H
#define MN_VECTOR_H

class Vector
{
public:
    // prototypes
    Vector(float x, float y, float z);
    float doProduct(Vector other);
    // std::tuple<float, float, float> doProduct(Vector other);

private:
    float x, y, z;

};


#endif