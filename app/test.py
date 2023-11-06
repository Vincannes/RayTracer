from app.domain.mn_point import Point
from app.domain.mn_vector import Vector
from app.domain.mn_image import Image
from app.domain.mn_color import Color
from app.domain.mn_light import Light
from app.domain.mn_material import Material, ChessMaterial
from app.domain.mn_objects import Sphere
from app.domain.mn_scene import Scene
from app.domain.mn_engine import RenderEngine

def main_2():
    WIDTH = 20
    HEIGHT = 20
    camera = Vector(0, -0.35, -1)
    objects = [
        # Plane
        # Sphere(Point(0, 10000.5, 1), 10000.0,
        #        ChessMaterial(color1=Color.from_hex("#420500"),
        #                      color2=Color.from_hex("#e6b87d"),
        #                      ambient=0.2, reflection=0.2)
        #        ),
        # Blue Ball
        Sphere(Point(0.75, -0.1, 1), 0.6, Material(Color.from_hex("#0000FF"))),
        # Pink Ball
        # Sphere(Point(-0.75, -0.1, 2.25), 0.6, Material(Color.from_hex("#803980"))),
    ]
    lights = [
        Light(Point(1.5, -0.5, -10), Color.from_hex("#FFFFFF")),
        # Light(Point(-0.5, -10.5, 5.0), Color.from_hex("#E6E6E6"))
    ]
    scene = Scene(camera, objects, lights, WIDTH, HEIGHT)
    engine = RenderEngine()
    image = engine.render(scene)
    image.write_ppm("D:\\Desk\\python\\RayTracer\\tests\\test4.mn")

def main():
    WIDTH = 320
    HEIGHT = 200
    camera = Vector(0, 0, -1)
    objects = [Sphere(Point(0, 0, 0), 0.5, Material(Color.from_hex("#FF0000")))]
    scene = Scene(camera, objects, [Light(Point(1.5, -0.5, -10), Color.from_hex("#FFFFFF"))], WIDTH, HEIGHT)
    engine = RenderEngine()
    image = engine.render(scene)
    image.write_ppm("D:\\Desk\\python\\RayTracer\\tests\\test3.mn")

if __name__ == "__main__":
    main()
