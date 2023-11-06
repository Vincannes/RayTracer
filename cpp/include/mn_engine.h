#include <vector>
#include <memory>

#include <mn_scene.h>
#include <mn_image.h>

#ifndef MN_ENGINE_H
#define MN_ENGINE_H

struct IntersectionResult {
    float dist;
    std::shared_ptr<Sphere> sphere;
};

class RenderEngine {
public:

    static const int MAX_DEPTH;
    static const float MIN_DISPLACE;

    RenderEngine();
    Image render(Scene scene);
    Color rayTrace(Ray ray, Scene scene, float depth);
    IntersectionResult findNearestObj(Ray ray, Scene scene);
    Color colorAt(Sphere obj_hit, Vector hit_pos, Vector normal, Scene scene);


private:
};

#endif
