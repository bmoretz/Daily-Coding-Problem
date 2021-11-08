from random import uniform
from math import pow

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

'''Shuffle.

Write a method to shuffle a deck of cards. It must be a perfect shuffle --
in  other words, each of the 51! permutations of the deck has to be equally
likely. Assume that you are given a random number generator which is perfect.
'''

from enum import Enum
from random import randint

class Suite(Enum):
    Hearts = 1
    Aces = 2
    Spades = 3
    Clubs = 4

class Deck():

    def __init__(self):
        self.cards = self._get_deck()
    
    def _get_suite(self, suite : Suite ):
        
        face = ['J', 'Q', 'K', 'A']
        num = [str(n) for n in range(2, 11)]

        cards = []

        for c in num + face:
            cards += [(suite.name, c)]
            
        return cards

    def get(self):
        return self.cards

    def get_rand(self, minimum, maximum):
        # assume perfect random uniform
        return randint(minimum, maximum)

    def _get_deck(self):
        
        deck = []

        for suite in Suite:
            deck += self._get_suite(suite)

        return deck

    def shuffle(self):
        
        n = len(self.cards)

        for index in range(n):
            # uniform draw (0, 51)
            draw = self.get_rand(0, n - 1)

            # swap k & i
            self.cards[index], self.cards[draw] = \
                self.cards[draw], self.cards[index]

'''Random Set.

Write a method to randomly generate a set of m integers from 
an array of size n. Each element must have equal probability
to be chosen.
'''

from random import randint

def get_unique_set(n, k):

    if k < n:
        raise RuntimeError('Cannot generate a unique set with k < n.')

    results = set()
    
    while len(results) < n:

        new = randint(0, k)

        if new not in results:
            results.add(new)

    return results

def get_random_set(data, m):

    bag = list(data)
    results = []

    while len(results) < m:
        
        index = randint(0, len(bag) - 1)

        results += [bag[index]]
        del bag[index]

    return results