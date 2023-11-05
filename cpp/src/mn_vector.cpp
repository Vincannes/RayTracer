#include <cmath>
#include <iostream>

#include "mn_vector.h"

Vector::Vector(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector::doProduct(Vector other)
{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

float Vector::magnitude()
{
    return sqrt(doProduct(*this));
}

NormValues Vector::normalize()
{
    float norm_x = this->x / magnitude();
    float norm_y = this->y / magnitude();
    float norm_z = this->z / magnitude();
    return {norm_x, norm_y, norm_z};
}
