#include "mn_color.h"

#ifndef MN_MATERIALS_H
#define MN_MATERIALS_H

class Material {
public:
    Material();
    Material(const Color& color, float ambient, float diffuse, float specular, float reflection);

    Color color;
    float ambient, diffuse, specular, reflection;

    Color colorAt(Vector position);

private:
};

#endif // MN_MATERIALS_H
