#include <iostream>
#include "mn_light.h"

Light::Light(PositionPoint pos, Color color) : pos(pos), color(color) {}

// Utilisation de la méthode statique de la classe Color pour définir la valeur par défaut de la couleur.
Light::Light(PositionPoint pos) : pos(pos), color(Color::fromHex("#FFFFFF")) {}
