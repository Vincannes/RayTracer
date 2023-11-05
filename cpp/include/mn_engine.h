#include <vector>

#include <mn_scene.h>
#include <mn_image.h>

#ifndef MN_ENGINE_H
#define MN_ENGINE_H

class RenderEngine {
public:

    RenderEngine();
    Image render(Scene scene);

private:
};

#endif
