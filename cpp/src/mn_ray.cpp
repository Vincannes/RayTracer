#include <cmath>
#include <iostream>

#include "mn_ray.h"

Ray::Ray(Vector origin, Vector direction)
{
    this->origin = origin;
    this->direction = direction;
}

