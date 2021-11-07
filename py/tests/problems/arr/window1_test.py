import unittest

from problems.arr import window1

class Test_SmallestWindow(unittest.TestCase):

    def setUp(self):
        pass
    
    def test_case1(self):
        assert window1( [3, 7, 5, 6, 9]) == (1, 3)
    
    def test_case2(self):
        assert window1( [3, 7, 5, 6, 9, 2, 3, 14, 15, 16, 17, 1.5]) == (1, 11)