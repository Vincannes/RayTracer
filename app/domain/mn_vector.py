from app.domain.mn_math_utils import square_root


class Vector(object):
    """A three element vector used in 3D Graphics.
    """

    def __init__(self, x=0.0, y=0.0, z=0.0):
        self.x = x
        self.y = y
        self.z = z

    def __repr__(self):
        return f"Vector({self.x}, {self.y}, {self.z})"

    def __add__(self, addend):
        if isinstance(addend, Vector):
            return Vector(self.x + addend.x, self.y + addend.y, self.z + addend.z)
        return Vector(self.x, self.y, self.z)

    def __sub__(self, subtrahend):
        if isinstance(subtrahend, Vector):
            return Vector(self.x - subtrahend.x, self.y - subtrahend.y, self.z - subtrahend.z)
        return Vector(self.x, self.y, self.z)

    def __mul__(self, factor):
        if isinstance(factor, Vector):
            return Vector(self.x * factor.x, self.y * factor.y, self.z * factor.z)
        return Vector(self.x, self.y, self.z)

    def __truediv__(self, divisor):
        if isinstance(divisor, Vector):
            return Vector(self.x / (divisor.x + 0.00000001), self.y / (divisor.y + 0.00000001),
                          self.z / (divisor.z + 0.00000001))
        return Vector(self.x, self.y, self.z)

    def magnitude(self):
        """
        :return: [float]
        """
        return square_root(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def do_product(self, other):
        """
        :param other: [Vector]
        :return:
        """
        return self.x * other.x + self.y * other.y + self.z * other.z

    def normalize(self):
        """
        :return: Vector(int, int, int)
        """
        return self / self.magnitude()

    def to_rgb(self):
        """

        :return: [tuple]
        """
        r, g, b = self.x, self.y, self.z
        if r < 0:
            r = 0
        elif r > 1:
            r = 1
        if g < 0:
            g = 0
        elif g > 1:
            g = 1
        if b < 0:
            b = 0
        elif b > 1:
            b = 1
        return r * 255, g * 255, b * 255


if __name__ == "__main__":
    v1 = Vector(1, -2, -2)
    v2 = Vector(3, 6, 8)

    print(v1 + v2)
    print(v1 - v2)
    print(v1 * v2)
    print(v1 / v2)
    # print(v1.magnitude())
    # print(v1.normalize())
