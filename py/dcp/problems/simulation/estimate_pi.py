from random import uniform

'''Estimate Pi.

The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.
'''

def estimate_pi(iters : int = 10e6):

    def generate():
        return (uniform(-1, 1), uniform(-1, 1))
    
    def is_in_circle(coords):
        return coords[0] * coords[0] + coords[1] * coords[1] < 1

    in_circle = 0

    for _ in range(int(iters)):
        if is_in_circle(generate()):
            in_circle += 1

    pi_over_four = in_circle / iters

    return pi_over_four * 4