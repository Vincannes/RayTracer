
class Scene(object):
    """
    Scene has all the information needed for ray tracing engine
    """
    def __init__(self, camera, objects, lights, width, height):
        self.camera = camera
        self.objects = objects
        self.lights = lights
        self.width = width
        self.height = height