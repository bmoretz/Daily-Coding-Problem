import unittest

from dcp.problems.daily.decoding import num_encoding1

class Test_NumEncodings(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):      
        assert num_encoding1('111') == 3

    def test_case2(self):
        assert num_encoding1('011') == 0

    def test_case3(self):
        assert num_encoding1('602') == 0