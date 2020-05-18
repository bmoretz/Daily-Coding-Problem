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

from py.problems.math import english_int
class Test_EnglishInt1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        n = None

        actual = english_int(n)
        expected = None

        assert actual == expected

    def test_case1(self):

        n = 413

        actual = english_int(n)
        expected = "Four Hundred Thirteen"

        assert actual == expected

    def test_case2(self):

        n = 111

        actual = english_int(n)
        expected = "One Hundred Eleven"

        assert actual == expected


    def test_case3(self):

        n = 1234

        actual = english_int(n)
        expected = "One Thousand Two Hundred Thirty Four"

        assert actual == expected

    def test_case4(self):

        n = 2300

        actual = english_int(n)
        expected = "Two Thousand Three Hundred"

        assert actual == expected

    def test_case4(self):

        n = 0

        actual = english_int(n)
        expected = "Zero"

        assert actual == expected

from py.problems.math import Ops
class Test_Operations(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):

        a, b = 9, 2

        actual = Ops.div(a, b)
        expected = 4

        assert actual == expected

    def test_case2(self):

        a, b = 9, 2

        actual = Ops.mult(a, b)
        expected = 18

        assert actual == expected

    def test_case3(self):

        a, b = 9, 2

        actual = Ops.sub(a, b)
        expected = 7

        assert actual == expected

    def test_case4(self):

        a, b = 1, 1

        actual = Ops.sub(a, b)
        expected = 0

        assert actual == expected

    def test_case5(self):

        a, b = 1, 1

        actual = Ops.div(a, b)
        expected = 1

        assert actual == expected