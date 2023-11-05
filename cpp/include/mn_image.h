#include <vector>
#include <mn_vector.h>

#ifndef MN_IMAGE_H
#define MN_IMAGE_H

class Image {
public:

    Image(int width, int height);

    static const int LARGEST_COLOR;
    int width;
    int height;
    std::vector<std::vector<Vector>> pixels;  // Matrice de pixels

    void set_pixel(int x, int y, Vector value);
    void write_ppm(const std::string& ppm_path) const;

private:
    static float _to_byte(float c);
};

#endif
