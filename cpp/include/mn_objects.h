#include <tuple>

#include <mn_ray.h>
#include <mn_materials.h>

#ifndef MN_OBJECTS_H
#define MN_OBJECTS_H

class Sphere {
/*A three element vector used in 3D Graphics.*/

public:

    Sphere(float center, float radius, Material material);

    float center, radius;
    Material material;

    Vector intersects(Ray ray);

private:

};


#endif