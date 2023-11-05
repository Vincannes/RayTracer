def square_root(number):
    """La méthode de Newton pour approximer la racine carrée d'un nombre
      en partant d'une estimation initiale et en itérant jusqu'à ce
      qu'une certaine précision soit atteinte.
    :param number: [float]
    :return: [float]
    """
    if number < 0:
        raise ValueError("Cannot square root negativ value")
    approximation = number
    while True:
        next_approximation = 0.5 * (approximation + number / approximation)
        if abs(approximation - next_approximation) < 1e-9:
            return next_approximation
        approximation = next_approximation
