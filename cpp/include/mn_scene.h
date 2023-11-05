#include <vector>

#include "mn_objects.h"
#include "mn_light.h" // Inclure le fichier d'en-tête de Light

#ifndef MN_SCENE_H
#define MN_SCENE_H

class Scene {
public:

    Scene(Vector camera, std::vector<Sphere> objects, std::vector<Light> lights, int width, int height); // Changer Sphere en Light

    Vector camera;
    std::vector<Sphere> objects; // Conserver les objets en tant que Spheres
    std::vector<Light> lights; // Utiliser la classe Light pour les lumières
    int width;
    int height;

private:
};

#endif // MN_MATERIALS_H
