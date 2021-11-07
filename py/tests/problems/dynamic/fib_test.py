import unittest

from dcp.problems.dynamic.fib import fib1

class Test_Fibonacci(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert fib1(10) == 55

from dcp.problems.dynamic.fib import fib2

class Test_Fibonacci(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        assert fib2(10) == 55
