import unittest

from dcp.problems.daily.decoding import dp_decode

class Test_NumEncodings(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):      
        assert dp_decode('111') == 3

    def test_case2(self):
        assert dp_decode('011') == 0

    def test_case3(self):
        assert dp_decode('602') == 0