import unittest

from dcp.problems.graph.snakes_ladders import minimum_turns1

class Test_SnakesLadders1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        snakes = {17 : 13, 52 : 29, 57 : 40, 62 : 22, 88 : 18, 95 : 51, 97 : 79}
        ladders = {3 : 21, 8 : 30, 28 : 84, 58 : 77, 75 : 86, 80 : 100, 90 : 91}

        n_squares = 100

        assert minimum_turns1(snakes, ladders, n_squares)