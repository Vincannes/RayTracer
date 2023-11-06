#include <iostream>
#include <memory>

#include "mn_scene.h"

Scene::Scene(Vector camera, const std::vector<std::shared_ptr<Sphere>>& objects, const std::vector<std::shared_ptr<Light>>& lights, int width, int height)
    : camera(camera), objects(objects), lights(lights), width(width), height(height) {
}
