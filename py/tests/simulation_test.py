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