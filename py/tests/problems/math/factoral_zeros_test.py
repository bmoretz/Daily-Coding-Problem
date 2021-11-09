import unittest

from dcp.problems.math.factoral_zeros import factorial_zeros1

class Test_FactorialZeros1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        n = None

        actual = factorial_zeros1(n)
        expected = None

        assert actual == expected

    def test_case1(self):

        n = 356

        actual = factorial_zeros1(n)
        expected = 87
        
        assert actual == expected

    def test_case2(self):

        n = 7 # fact(7) = 5040

        actual = factorial_zeros1(n)
        expected = 1
        
        assert actual == expected

    def test_case3(self):

        n = 184

        actual = factorial_zeros1(n)
        expected = 44
        
        assert actual == expected

    def test_case4(self):

        n = 64

        actual = factorial_zeros1(n)
        expected = 14
        
        assert actual == expected

    def test_case5(self):

        n = 500

        actual = factorial_zeros1(n)
        expected = 124
        
        assert actual == expected