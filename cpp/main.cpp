#include <vector>
#include <string>
#include <iostream>

#include "include/mn_vector.h"
#include "include/mn_point.h"
#include "include/mn_color.h"
#include "include/mn_scene.h"
#include "include/mn_light.h"
#include "include/mn_image.h"
#include "include/mn_objects.h"
#include "include/mn_materials.h"
#include "include/mn_engine.h"

void old()
{    
    Vector camera(1, -2, -2);
    Vector v2(3, 6, 8);

    PositionPoint p1(2, 3, 5);
    Color white = Color::fromHex("#420500");

    std::cout << camera.doProduct(v2) << std::endl;
    std::cout << camera.magnitude() << std::endl;
    std::cout << camera.normalize().x << " " << camera.normalize().y<< " " << camera.normalize().z << std::endl;

    std::cout << p1.x << std::endl;
    std::cout << "color  " << white.x << std::endl;

    // Material material(Color::fromHex("#FFFFFF"), 0.05f, 1.0f, 1.0f, 0.5f);
    Material mat2(Color::fromHex("#0000FF"));
    // std::cout << "materiale  " << material.color.y << std::endl;

    Sphere sphere(PositionPoint(0, 10000.5, 1), 10000.0, mat2);
    std::cout << "radius  " << sphere.radius << "  " << sphere.intersects(Ray(Vector(1, -2, 5), Vector(3, 1.2, 65))) << std::endl;

}

int main() {
    std::cout << "" << std::endl;

    int width = 320;
    int height = 200;

    Vector camera(0, -0.35, -1);
    std::vector<Sphere> objects = {
        Sphere(PositionPoint(0.75, -0.1, 1), 0.6, Material(Color::fromHex("#0000FF"))),
        Sphere(PositionPoint(-0.75, -0.1, 2.25), 0.6, Material(Color::fromHex("#803980")))
    };

    std::vector<Light> lights = {
        Light(PositionPoint(1.5, -0.5, -10), Color::fromHex("#FFFFFF")),
        Light(PositionPoint(-0.5, -10.5, 5.0), Color::fromHex("#E6E6E6"))
    };

    Scene scene(camera, objects, lights, width, height);
    RenderEngine engine;
    
    Image image = engine.render(scene);
    image.write_ppm("D:\\Desk\\python\\RayTracer\\tests\\test5.mn");
    return 1;
}
