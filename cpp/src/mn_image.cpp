#include <cmath>  // Pour la fonction round
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>  // Pour la fonction std::min et std::max

#include "mn_image.h"

const int Image::LARGEST_COLOR = 255;  // Initialisation de la constante statique

Image::Image(int width, int height)
{
    this->width=width;
    this->height=height;
    pixels.resize(height, std::vector<Vector>(width, Vector(0, 0, 0)));

}

void Image::set_pixel(int x, int y, Vector value)
{
    if (x >= 0 && x < width && y >= 0 && y < height) {
        pixels[y][x] = value;
    }
}

float Image::_to_byte(float c)
{
    double clampedValue = std::max(0.0, std::min(static_cast<double>(c * LARGEST_COLOR), static_cast<double>(LARGEST_COLOR)));
    return std::round(clampedValue);
}

void Image::write_ppm(const std::string& ppm_path) const {
    std::ofstream ppm_file(ppm_path);
    if (!ppm_file) {
        std::cerr << "Impossible d'ouvrir le fichier PPM : " << ppm_path << std::endl;
        return;
    }

    ppm_file << "P3\n" << this->width << " " << this->height << "\n" << LARGEST_COLOR << "\n";

    for (const auto& row : pixels) {
        for (const auto& color : row) {
            ppm_file << _to_byte(color.x) << " " << _to_byte(color.y) << " " << _to_byte(color.z) << " ";
        }
        ppm_file << "\n";
    }
}