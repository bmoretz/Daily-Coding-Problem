import unittest

from py.problems.math import line_intersect1

class Test_LineIntersect1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        li = line_intersect1

        actual = li.intersect(None, None)
        expected = None

        assert actual == expected

    def test_case1(self):

        li = line_intersect1

        l1 = li.make_line(1, 6, 7, 2)
        l2 = li.make_line(2, 4, 7, 8)

        actual = li.intersect(l1, l2)
        expected = li.Point(2.91, 4.73)

        assert actual == expected

    def test_case2(self):

        li = line_intersect1

        l1 = li.make_line(3, 8, 7, 8)
        l2 = li.make_line(3, 2, 6, 2)

        actual = li.intersect(l1, l2)
        expected = None

        assert actual == expected

    def test_case3(self):

        li = line_intersect1

        l1 = li.make_line(3, 8, 7, 8)
        l2 = li.make_line(3, 8, 7, 8)

        actual = li.intersect(l1, l2)
        expected = li.Point(3, 8)

        assert actual == expected

    def test_case4(self):

        li = line_intersect1

        l1 = li.make_line(9, 1, 3, 4)
        l2 = li.make_line(2, 8, 5, 3)

        actual = li.intersect(l1, l2)
        expected = li.Point(5, 3)

        assert actual == expected

    def test_case5(self):

        li = line_intersect1

        l1 = li.make_line(-3, -5, 12, 4)
        l2 = li.make_line(3, 4, -12, 15)

        actual = li.intersect(l1, l2)
        expected = None

        assert actual == expected

from py.problems.math import factorial_zeros1
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