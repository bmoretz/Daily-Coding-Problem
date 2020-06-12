import unittest

from py.problems.simulation import estimate_pi
class Test_SimulatePi(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        assert round( estimate_pi(10e5), 2) == 3.14

from py.problems.simulation import Deck
class Test_Shuffle(unittest.TestCase):

    def setUp(self):
        pass

    def test_randomness(self):
        
        # this should basically never have a
        # collision, even with pretty large number of
        # simulations
        iters = 1000

        seen = set()
        deck = Deck()

        for _ in range(iters):
            
            deck.shuffle()

            order = ','.join([str(card) for card in deck.get()])

            seen.add(order)

        assert len(seen) == iters

import numpy as np
from collections import defaultdict
from py.problems.simulation import get_unique_set, get_random_set
class Test_RandomSet(unittest.TestCase):

    def setUp(self):
        pass

    def test_randomness(self):
        
        master = get_unique_set(50, 100) # master set of items
        iters = 1e4 # num sims
        freq = defaultdict(int) # cum freq table
        total = 0 # counter

        # run sim
        for _ in range(int(iters)):

            sub = get_random_set(master, 5)

            for i in sub:
                freq[i] += 1

            total += len(sub)
        
        # calc freq
        frequencies = []
        for k in freq:
            frequencies += [freq[k] / total]

        deltas = [None] * (len(frequencies) - 1)
        epsilon = 0.001

        for index in range(1, len(frequencies)):
            deltas[index - 1] = abs(frequencies[index] - frequencies[index - 1])

        assert sum([0 if d < epsilon else 1 for d in deltas]) == 0