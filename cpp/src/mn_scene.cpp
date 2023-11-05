#include <iostream>

#include "mn_scene.h"

Scene::Scene(Vector camera, std::vector<Sphere> objects, std::vector<Light> lights, int width, int height)
{
    this->camera=camera;
    this->objects=objects;
    this->lights=lights;
    this->width=width;
    this->height=height;
}

