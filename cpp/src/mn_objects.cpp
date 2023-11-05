#include <cmath>
#include <iostream>

#include "mn_objects.h"

Sphere::Sphere(PositionPoint center, float radius, Material material)
    : center(center), radius(radius), material(material)
{
    // Pas besoin d'initialiser manuellement les membres, car ils sont initialisés via la liste d'initialisation.
}

float Sphere::intersects(Ray ray)
{
    float result = -1.0f;  // Initialisation avec une valeur invalide pour indiquer qu'il n'y a pas d'intersection

    // Calculez les coordonnées du vecteur "sphere_to_ray" correctement en utilisant la classe PositionPoint.
    Vector sphere_to_ray = Vector(
        ray.origin.x - center.x,
        ray.origin.y - center.y,
        ray.origin.z - center.z
    );

    float b = 2 * sphere_to_ray.doProduct(sphere_to_ray);
    float c = sphere_to_ray.doProduct(sphere_to_ray) - radius * radius;
    float discriminant = b * b - 4 * c;
    if (discriminant >= 0) {
        float dist = (-b - sqrt(discriminant));
        if (dist > 0) {
            result = dist;
        }
    }
    return result;
}
