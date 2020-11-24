import unittest

from py.problems.backtrack import num_queens1
class Test_NumEncodings(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert num_queens1(4) == 2

    def test_case2(self):

        assert num_queens1(10) == 724