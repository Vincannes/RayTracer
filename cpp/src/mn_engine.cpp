#include <iostream>

#include "mn_engine.h"

RenderEngine::RenderEngine()
{

}

Image RenderEngine::render(Scene scene)
{
    int widht = scene.width;
    int height = scene.height;
    Image pixels(widht, height);
    return pixels;
}