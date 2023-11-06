#include <tuple>

#include <mn_ray.h>
#include <mn_point.h>
#include <mn_materials.h>

#ifndef MN_OBJECTS_H
#define MN_OBJECTS_H

class Sphere {
/*Sphere has center, radius and material.*/

public:

    Sphere(PositionPoint center, float radius, Material material);

    PositionPoint center;
    float radius;
    Material material;

    float intersects(Ray ray);
    Vector normal(Vector surface_point);
;
private:

};


#endif