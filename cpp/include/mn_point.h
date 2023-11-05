#include <mn_vector.h>

#ifndef MN_POINT_H
#define MN_POINT_H


class PositionPoint : public Vector
{
/*Point stores 3D coordinates. An Alias for Vector.*/

public:

    PositionPoint() noexcept;
    PositionPoint(float x, float y, float z) noexcept;

private:

};


#endif