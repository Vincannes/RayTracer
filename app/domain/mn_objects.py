from app.domain.mn_math_utils import square_root


class MnObject(object):

    def __init__(self):
        pass


class Sphere(object):
    """
    Sphere has center, radius and material
    """

    def __init__(self, center, radius, material):
        # super().__init__(x, y, z)
        self.center = center
        self.radius = radius
        self.material = material

    def intersects(self, ray):
        """ Checks if ray intersets this object.
        :param ray: [Vector]
        :return: Returns distance to intersection or None if not intersection
        """
        sphere_to_ray = ray.origin - self.center
        # a = 1
        b = 2 * ray.direction.do_product(sphere_to_ray)
        c = sphere_to_ray.do_product(sphere_to_ray) - self.radius * self.radius
        discriminant = b * b - 4 * c
        if discriminant >= 0:
            dist = (-b - square_root(discriminant)) / 2
            if dist > 0:
                return dist
        return None

    def normal(self, surface_point):
        """
        Returns surface normal to the point on sphere's surface
        :param surface_point:
        :return:
        """
        return (surface_point - self.center).normalize()


class Card(object):

    def __init__(self):
        pass

    def intersects(self, ray):
        pass
