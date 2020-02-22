import unittest

from problems.dynamic import staircase1, staircase2

class Test_Staircase(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        n = 4

        assert staircase1(n, range(1, n)) == 7

    def test_case2(self):

        n = 4
        
        assert staircase2(n, range(1, n)) == 7