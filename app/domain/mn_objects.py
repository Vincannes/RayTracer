
class MnObject(object):

    def __init__(self, x=0.0, y=0.0, z=0.0):
        self.x = x
        self.y = y
        self.z = z


class Sphere(MnObject):

    def __init__(self, x, y, z):
        super().__init__(x, y, z)


class Card(MnObject):

    def __init__(self, x, y, z):
        super().__init__(x, y, z)
