#include <cmath>
#include <iostream>

#include "mn_objects.h"

Sphere::Sphere(PositionPoint center, float radius, Material material)
    : center(center), radius(radius), material(material) {}

float Sphere::intersects(Ray ray)
{
    /* Checks if ray intersets this object.
        :param ray: [Vector]
        :return: Returns distance to intersection or None if not intersection
    */
    float result = -1.0f;

    Vector sphere_to_ray = ray.origin - center;

    float a = 1;
    float b = 2 * ray.direction.doProduct(sphere_to_ray);
    float c = sphere_to_ray.doProduct(sphere_to_ray) - radius * radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        float dist = (-b - sqrt(discriminant)) / 2 * a;
        if (dist > 0) {
            result = dist;
        }
    }
    return result;
}

Vector Sphere::normal(Vector surface_point)
{
    // Calcul de la différence entre surface_point et self.center
    Vector difference = surface_point - this->center;

    // Calcul de la norme (longueur) du vecteur difference
    float length = std::sqrt(difference.x * difference.x + difference.y * difference.y + difference.z * difference.z);
    
    // Normalisation du vecteur difference
    return Vector(
        difference.x / length,
        difference.y / length,
        difference.z / length
    );
}
