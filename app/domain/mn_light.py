from app.domain.mn_color import Color

class Light(object):
    """
    Light represents a point light source of a certain color
    """

    def __init__(self, pos, color=Color.from_hex("#FFFFFF")):
        self.position = pos
        self.color = color


