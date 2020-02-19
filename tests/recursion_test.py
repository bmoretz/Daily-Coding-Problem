import unittest

from problems.recursion import matches

class Test_RegularExpression(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        s, r = 'ray', 'ra.'

        assert matches(s, r) == True

    def test_case2(self):

        s, r = 'raymond', 'ra.'

        assert matches(s, r) == False
