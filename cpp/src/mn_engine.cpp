#include <cmath>
#include <limits>
#include <algorithm>
#include <iostream>

#include "mn_engine.h"

const int RenderEngine::MAX_DEPTH = 5;
const float RenderEngine::MIN_DISPLACE = 0.0001; 

RenderEngine::RenderEngine()
{

}

Image RenderEngine::render(Scene scene)
{
    int width = scene.width;
    int height = scene.height;
    float aspect_ratio = static_cast<float>(width) / height;
    float x0 = -1.0;
    float x1 = +1.0;
    float xstep = (x1 - x0) / (width - 1);
    float y0 = -1.0 / aspect_ratio;
    float y1 = +1.0 / aspect_ratio;
    float ystep = (y1 - y0) / (height - 1);

    Image pixels(width, height);
    Vector camera = scene.camera;

    for(int j = height; j >= 0; j--){
        float y = y0 + j *ystep;

        for(int i=0; i<=width; i++){
            float x = x0 + i * xstep;
            Ray ray(camera, PositionPoint(x, y ,0)-camera);
            Color pixel_color = rayTrace(ray, scene, 0);
            pixels.set_pixel(i, j, pixel_color);
        }
    }
    return pixels;
}

Color RenderEngine::rayTrace(Ray ray, Scene scene, float depth=0.0)
{
    Color color(0, 0, 0);
    
    // Find the nearest object hit by the ray in the scene
    IntersectionResult result_hit = findNearestObj(ray, scene);
    float dist_hit = result_hit.dist;
    std::shared_ptr<Sphere> sphere_ptr = result_hit.sphere;

    if(!sphere_ptr) return color;
    Sphere obj_hit = *sphere_ptr;

    Vector hit_pos = ray.origin + ray.direction * dist_hit;
    Vector hit_norm = obj_hit.normal(hit_pos);
    
    color += colorAt(obj_hit, hit_pos, hit_norm, scene);

    // calcul depth
    if(depth < MAX_DEPTH){
        Vector new_ray_pos = hit_pos + hit_norm * MIN_DISPLACE;
        
        // float temp =;
        Vector new_ray_dir = ray.direction - hit_norm * (2 * ray.direction.doProduct(hit_norm));
        Ray new_ray(new_ray_pos, new_ray_dir);

        // Attenuate the reflected ray found by the reflection coeff
        color += rayTrace(new_ray, scene, depth+1) * obj_hit.material.reflection;
    }

    return color;
}

IntersectionResult RenderEngine::findNearestObj(Ray ray, Scene scene)
{
    float distMin;
    std::shared_ptr<Sphere> objHit = nullptr;

    for (const auto& obj : scene.objects) {
        float dist = obj->intersects(ray);
        if (dist != -1 && (objHit == nullptr || dist < distMin)) {
            distMin = dist;
            objHit = obj;
            // std::cout << "object: " << obj->radius << "  distance: " << distMin << std::endl;
        }
    }

    return {distMin, objHit};
}

Color RenderEngine::colorAt(Sphere obj_hit, Vector hit_pos, Vector normal, Scene scene)
{
    Material material = obj_hit.material;
    Color obj_color = material.colorAt(hit_pos);
    Vector to_cam = scene.camera - hit_pos;
    int specular_k = 50;
    Color color =Color::fromHex("#000000") * material.ambient;

    // Light calculation
    for(const auto& light : scene.lights) {
       Ray ray_to_light(hit_pos, light->pos - hit_pos); 

        // Diffuse shading (Lambert)
        color += obj_color * material.diffuse * std::max(normal.doProduct(ray_to_light.direction), 0.0f);
        
        // Specular shading (Blinn-Phong)
        Vector half_vector(ray_to_light.direction + to_cam);
        Vector half_vector_nor(
            half_vector.normalize().x,
            half_vector.normalize().y,
            half_vector.normalize().z
        );

        color += light->color * material.specular * std::pow(std::max(normal.doProduct(half_vector_nor), 0.0f), specular_k);
    }

    // std::cout << color.x << " "<< color.y << " " << color.z << std::endl; 
    return color;
}
