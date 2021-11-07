import unittest

from dcp.problems.arr.products import product3

class Test_ArrayProduct3(unittest.TestCase):

    def setUp(self):
        pass
    
    def test_case1(self):
        assert product3( [1, 2, 3, 4, 5] ) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert product3( [3, 2, 1] ) == [2, 3, 6]