

class Image(object):

    LARGEST_COLOR = 255

    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.pixels = [[None for _ in range(width)] for _ in range(height)]

    def set_pixel(self, x, y, col):
        self.pixels[y][x] = col

    def write_ppm(self, ppm_path):
        to_ppm = f"P3\n{self.width} {self.height} \n{Image.LARGEST_COLOR}\n"
        ppm_file = open(ppm_path, "w")
        ppm_file.write(to_ppm)

        # Parse every Pixels
        for row in self.pixels:
            for color in row:
                print(color)
                pixel = "{} {} {} ".format(
                    Image._to_byte(color.x),
                    Image._to_byte(color.y),
                    Image._to_byte(color.z),
                )
                # print(pixel)
                ppm_file.write(pixel)
            ppm_file.write("\n")

    @staticmethod
    def _to_byte(c):
        return round(max(min(c*Image.LARGEST_COLOR, Image.LARGEST_COLOR), 0))
