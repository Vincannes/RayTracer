#include <cmath>
#include <string>
#include <iostream>

#include "mn_materials.h"

Material::Material() : color(Color()), ambient(0.0f), diffuse(0.0f), specular(0.0f), reflection(0.0f) {}

Material::Material(const Color& color, float ambient, float diffuse, float specular, float reflection)
    : color(color), ambient(ambient), diffuse(diffuse), specular(specular), reflection(reflection) {}

Color Material::colorAt(Vector position) {
    return this->color;
}