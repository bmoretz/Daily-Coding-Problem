import unittest

from problems.dynamic import fib1, fib2
from problems.dynamic import staircase1, staircase2
from problems.dynamic import num_encodings1, num_encodings2

class Test_Fibonacci(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert fib1(10) == 55

    def test_case2(self):
        
        assert fib2(10) == 55

class Test_Staircase(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        n = 4

        assert staircase1(n, range(1, n)) == 7

    def test_case2(self):

        n = 4
        
        assert staircase2(n, range(1, n)) == 7

class Test_NumEncodings(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert num_encodings1('111') == 3

    def test_case2(self):

        assert num_encodings2('111') == 3