import os, sys

from app.domain.mn_vector import Vector
from app.domain.mn_image import Image
from app.domain.mn_color import Color
from app.domain.mn_math_utils import square_root

WIDHT = 3
HEIGHT = 2
RAYON = 50

FILE_TO = "D:\\Desk\\python\\RayTracer\\tests\\test_01.ppm"


def write_image(width, height):
    to_ppm = f"P3\n{width} {height} \n{255}\n"
    fichier = open(FILE_TO, "w")
    fichier.write(to_ppm)

    # Parse every Pixels
    for y in range(HEIGHT-1, -1, -1): # to start at bottom left
        for x in range(WIDHT):

            red = 255  #int(float(x / WIDHT) * 255)
            green = 255 #int(float(y / HEIGHT) * 255)
            blue = 255 #int(0.2 * 255)

            pixel_black = str(0) + " " + str(0) + " " + str(0) + "\n"
            pixel_white = str(red) + " " + str(green) + " " + str(blue) + "\n"

            # Utiliser l'équation du cercle pour vérifier si le pixel est à l'intérieur du cercle
            is_inside_circle = (x - WIDHT // 2) ** 2 + (y - HEIGHT // 2) ** 2 <= RAYON ** 2

            if is_inside_circle:
                pixel = pixel_white
            else:
                pixel = pixel_black
            print()
            fichier.write(pixel)
    fichier.write("\n")

def main():
    im = Image(WIDHT, HEIGHT)
    red = Color(1, 0, 0)
    green = Color(0, 1, 0)
    blue = Color(0, 0, 1)
    im.set_pixel(0, 0, red)
    im.set_pixel(1, 0, green)
    im.set_pixel(2, 0, blue)

    im.set_pixel(0, 1, red+green)
    im.set_pixel(1, 1, red+green+blue)
    im.set_pixel(2, 1, red*0.001)

    im.write_ppm("test2.ppm")

main()
