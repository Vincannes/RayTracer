#ifndef MN_MATERIALS_H
#define MN_MATERIALS_H

#include "mn_color.h"

class Material {
public:
    Material(const Color& color, float ambient, float diffuse, float specular, float reflection);

    Color color;
    float ambient, diffuse, specular, reflection;

    Color colorAt(Vector position);

private:
};

#endif // MN_MATERIALS_H
