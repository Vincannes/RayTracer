import os, sys

WIDHT = 200
HEIGHT = 150
RAYON = 50

FILE_TO = "D:\\Desk\\python\\RayTracer\\tests\\test_01.ppm"

to_ppm = f"P3\n{WIDHT} {HEIGHT} \n{255}\n"
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

        fichier.write(pixel)
    fichier.write("\n")

fichier.close()
