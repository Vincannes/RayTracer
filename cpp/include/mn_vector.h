#include <tuple>

#ifndef MN_VECTOR_H
#define MN_VECTOR_H


struct NormValues {
    float x, y, z;
};

class Vector {
/*A three element vector used in 3D Graphics.*/

public:

    Vector();
    Vector(float x, float y, float z);
    float x, y, z;
    float doProduct(Vector other);
    float magnitude();
    NormValues normalize();

private:

};


#endif