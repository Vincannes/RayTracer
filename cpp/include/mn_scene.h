#include <vector>

#include "mn_objects.h"
#include "mn_light.h" // Inclure le fichier d'en-tête de Light

#ifndef MN_SCENE_H
#define MN_SCENE_H

class Scene {
public:

    Scene(
        Vector camera, 
        const std::vector<std::shared_ptr<Sphere>>& objects, 
        const std::vector<std::shared_ptr<Light>>& lights, 
        int width, int height
    );

    Vector camera;
    std::vector<std::shared_ptr<Sphere>> objects;
    std::vector<std::shared_ptr<Light>> lights;
    int width;
    int height;

private:
};

#endif // MN_MATERIALS_H
