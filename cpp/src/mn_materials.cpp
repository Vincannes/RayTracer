#include "mn_materials.h"

Material::Material()
    : color(Color(0.0f, 0.0f, 0.0f)),
      ambient(0.05f),
      diffuse(1.0f),
      specular(1.0f),
      reflection(0.5f)
{
}

Material::Material(const Color& color)
    : color(color),
      ambient(0.05f),
      diffuse(1.0f),
      specular(1.0f),
      reflection(0.5f)
{
}

Material::Material(const Color& color, float ambient, float diffuse, float specular, float reflection)
    : color(color),
      ambient(ambient),
      diffuse(diffuse),
      specular(specular),
      reflection(reflection)
{
}

Color Material::colorAt(Vector position)
{
    return color;
}
