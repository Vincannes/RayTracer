from app.domain.mn_math_utils import square_root


class Vector(object):
    """A three element vector used in 3D Graphics.
    """

    def __init__(self, x=0.0, y=0.0, z=0.0):
        self.x = x
        self.y = y
        self.z = z

    def __str__(self):
        return "({}, {}, {})".format(self.x, self.y, self.z)

    def do_product(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    def magnitude(self):
        return square_root(self.do_product(self))

    def normalize(self):
        return self / self.magnitude()

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y, self.z - other.z)

    def __mul__(self, other):
        assert not isinstance(other, Vector)
        return Vector(self.x * other, self.y * other, self.z * other)

    def __rmul__(self, other):
        return self.__mul__(other)

    def __truediv__(self, other):
        assert not isinstance(other, Vector)
        return Vector(self.x / other, self.y / other, self.z / other)

if __name__ == "__main__":
    v1 = Vector(1, -2, -2)
    v2 = Vector(3, 6, 8)

    print(v1.do_product(v2))
    print(v1.magnitude())
    print(v1.normalize())
    # print(v1 + v2)
    # print(v1 - v2)
    # print(v1 * v2)
    # print(v1 / v2)
    # print(v1.magnitude())
    # print(v1.normalize())
