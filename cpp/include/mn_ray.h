#include <tuple>

#include <mn_vector.h>

#ifndef MN_RAY_H
#define MN_RAY_H

class Ray {
/*A three element vector used in 3D Graphics.*/

public:

    Ray(Vector origin, Vector direction);

    Vector origin, direction;

private:

};


#endif