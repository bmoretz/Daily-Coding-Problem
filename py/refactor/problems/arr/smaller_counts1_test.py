import unittest

from problems.arr import smaller_counts1

class Test_SmallerCounts1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert smaller_counts1( [3, 4, 9, 6, 1]) == [1, 1, 2, 1, 0]
    
    def test_case2(self):
        assert smaller_counts1( [2, 5, 4, 7, 8]) == [0, 1, 0, 0, 0]