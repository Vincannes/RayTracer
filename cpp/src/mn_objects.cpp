#include <cmath>
#include <iostream>

#include "mn_objects.h"

Sphere::Sphere(float center, float radius, Material material)
{
    this->center = center;
    this->radius = radius;
    this->material = material;
}

