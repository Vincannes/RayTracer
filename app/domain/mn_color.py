from app.domain.mn_vector import Vector



class Color(Vector):
    """Stores color as RGB triplets. An alias for Vector"""

    @classmethod
    def from_hex(cls, hexcolor="#000000"):
        x = int(hexcolor[1:3], 16) / 255.0
        y = int(hexcolor[3:5], 16) / 255.0
        z = int(hexcolor[5:7], 16) / 255.0
        return cls(x, y, z)

    # def __init__(self, x=0.0, y=0.0, z=0.0):
    #     self.x = x
    #     self.y = y
    #     self.z = z
    #
    # def __repr__(self):
    #     return f"Color({self.x}, {self.y}, {self.z})"
    #
    # def __add__(self, addend):
    #     if isinstance(addend, Color):
    #         return Color(self.x + addend.x, self.y + addend.y, self.z + addend.z)
    #     return Color(self.x, self.y, self.z)
    #
    # def __sub__(self, subtrahend):
    #     if isinstance(subtrahend, Color):
    #         return Color(self.x - subtrahend.x, self.y - subtrahend.y, self.z - subtrahend.z)
    #     return Color(self.x, self.y, self.z)
    #
    # def __mul__(self, factor):
    #     if isinstance(factor, Color):
    #         return Color(self.x * factor.x, self.y * factor.y, self.z * factor.z)
    #     elif isinstance(factor, int) or isinstance(factor, float):
    #         return Color(self.x*factor, self.y*factor, self.z*factor)
    #     return Color(self.x, self.y, self.z)
    #
    # def __truediv__(self, divisor):
    #     if isinstance(divisor, Color):
    #         return Color(self.x / (divisor.x + 0.00000001), self.y / (divisor.y + 0.00000001),
    #                       self.z / (divisor.z + 0.00000001))
    #     return Color(self.x, self.y, self.z)
    #
