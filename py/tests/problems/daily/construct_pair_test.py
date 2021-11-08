import unittest

from dcp.problems.daily.construct_pair import cons, car, cdr

class Test_ConstructPair(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        actual = car(cons(3, 4))
        expected = 3

        assert actual == expected

    def test_case2(self):

        actual = cdr(cons(3, 4))
        expected = 4

        assert actual == expected

    def test_case3(self):

        actual = car(cons(None, 4))
        expected = None

        assert actual == expected