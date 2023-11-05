#include <vector>

#include <mn_color.h>
#include <mn_point.h>

#ifndef MN_LIGHT_H
#define MN_LIGHT_H

class Light {
public:

    Light();
    Light(PositionPoint pos);
    Light(PositionPoint pos, Color color);

    PositionPoint pos;
    Color color;

private:
};

#endif // MN_MATERIALS_H
