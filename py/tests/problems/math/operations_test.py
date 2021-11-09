import unittest

from dcp.problems.math.operations import Ops

class Test_Operations(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):

        a, b = 9, 2

        actual = Ops.div(a, b)
        expected = 4

        assert actual == expected

    def test_case2(self):

        a, b = 9, 2

        actual = Ops.mult(a, b)
        expected = 18

        assert actual == expected

    def test_case3(self):

        a, b = 9, 2

        actual = Ops.sub(a, b)
        expected = 7

        assert actual == expected

    def test_case4(self):

        a, b = 1, 1

        actual = Ops.sub(a, b)
        expected = 0

        assert actual == expected

    def test_case5(self):

        a, b = 1, 1

        actual = Ops.div(a, b)
        expected = 1

        assert actual == expected