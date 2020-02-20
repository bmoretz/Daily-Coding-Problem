import unittest

from problems.recursion import matches
from problems.recursion import min_and_max1, min_and_max2

class Test_RegularExpression(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        s, r = 'ray', 'ra.'

        assert matches(s, r) == True

    def test_case2(self):

        s, r = 'raymond', 'ra.'

        assert matches(s, r) == False

class Test_RegularExpression(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        s, r = 'ray', 'ra.'

        assert matches(s, r) == True
