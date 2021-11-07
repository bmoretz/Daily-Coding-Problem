import unittest

from problems.daily import car, cons, cdr
class Test_Construct1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        assert car(cons(3, 4)) == 3

    def test_case2(self):
        assert cdr(cons(3, 4)) == 4