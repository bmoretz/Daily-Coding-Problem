import unittest

from dcp.problems.math.bisect_squares import BisectSquares

class Test_BisectSquares(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        Square = BisectSquares.Square

        s1, s2 = Square(2, 5, 2, 5), Square(5, 2, 5, 2)

        actual = s1.cut(s2)

        assert actual.p1.x == 3.5
        assert actual.p1.y == -1.0

        assert actual.p2.x == 3.5
        assert actual.p2.y == 8.0