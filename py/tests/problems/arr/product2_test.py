import unittest

from problems.arr import product2

class Test_ArrayProduct2(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert product2( [1, 2, 3, 4, 5] ) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert product2( [3, 2, 1] ) == [2, 3, 6]