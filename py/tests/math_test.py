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

from py.problems.math import BisectSquares
class Test_BisectSquares(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        Square = BisectSquares.Square
        Point = BisectSquares.Square.Point

        s1, s2 = Square(2, 5, 2, 5), Square(5, 2, 5, 2)

        actual = s1.cut(s2)

        assert actual.p1.x == 3.5
        assert actual.p1.y == -1.0

        assert actual.p2.x == 3.5
        assert actual.p2.y == 8.0
        
from py.problems.math import contiguous_seq1
class Test_ContiguousSeq1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_none(self):

        arr = None

        actual = contiguous_seq1(arr)
        expected = None

        assert actual == expected

    def test_case1(self):

        arr = [2, -8, 3, -2, 4, -10]

        actual = contiguous_seq1(arr)
        expected = 5

        assert actual == expected
    
    def test_case2(self):

        arr = [2, -8, 3, -7, 4, -10]

        actual = contiguous_seq1(arr)
        expected = None

        assert actual == expected

    def test_case3(self):

        arr = [2, -8, 3, -7, 4, -10, 12, -3]

        actual = contiguous_seq1(arr)
        expected = 9

        assert actual == expected

    def test_case4(self):

        arr = [2, -8, 3, -7, 4, -10, 12, -2, 4, -1]

        actual = contiguous_seq1(arr)
        expected = 13

        assert actual == expected

    def test_case5(self):

        arr = [2, -2, 3, -7, 4, -10, 7, -2, 4, -1]

        actual = contiguous_seq1(arr)
        expected = 8

        assert actual == expected

from py.problems.math import sum_swap
class Test_SumSwap1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_none(self):

        arr = None

        actual = sum_swap(arr, arr)
        expected = None

        assert actual == expected

    def test_case1(self):

        arr1, arr2 = [4, 1, 2, 1, 1, 2], [3, 6, 3, 3]

        actual = sum_swap(arr1, arr2)
        expected = {(4, 6), (1, 3)}

        assert actual == expected

    def test_case2(self):

        arr1, arr2 = [4, 1, 2, 1, 1, 2], [3, 6, 3, 3, 2]

        actual = sum_swap(arr1, arr2)
        expected = set()

        assert actual == expected

    def test_case3(self):

        arr1, arr2 = [4, 1, 2, 1, 1, 2], [3, 6, 3, 3, 5, 1]

        actual = sum_swap(arr1, arr2)
        expected = {(1, 6)}

        assert actual == expected

    def test_case4(self):

        arr1, arr2 = [4, 1, 2, 1, 1, 2, 4, 2, 1], [1, 6, 2, 3, 5, 1]

        actual = sum_swap(arr1, arr2)
        expected = {(1, 1), (2, 2)}

        assert actual == expected

    def test_case5(self):

        arr1, arr2 = [4, 1, 2, 1, 1, 2, 4, 2, 1, 2], [1, 6, 2, 3, 5, 1]

        actual = sum_swap(arr1, arr2)
        expected = {(2, 1), (4, 3)}

        assert actual == expected

from py.problems.math import calculate1
class Test_Calculate1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_none(self):

        expr = None

        actual = calculate1(expr)
        expected = None

        assert actual == expected

    def test_case1(self):

        expr = "2*3+5/6*3+15"

        actual = calculate1(expr)
        expected = 23.5

        assert actual == expected

    def test_case2(self):

        expr = "2*3*2+5/6*3+15"

        actual = calculate1(expr)
        expected = 29.5

        assert actual == expected

    def test_case3(self):

        expr = "2*3*2+5/6*3+15/5"

        actual = calculate1(expr)
        expected = 17.5

        assert actual == expected

    def test_case4(self):

        expr = "1*1/1*1/1"

        actual = calculate1(expr)
        expected = 1

        assert actual == expected

    def test_case5(self):

        expr = "1+2+3+4+5/5"

        actual = calculate1(expr)
        expected = 11

        assert actual == expected