import unittest

from problems.arr import product1, product2, product3
from problems.arr import window1
from problems.arr import max_subarray_sum1
from problems.arr import smaller_counts1
from problems.arr import build_mat, rotate1, rotate2

class Test_ArrayProduct1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert product1( [1, 2, 3, 4, 5] ) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert product1( [3, 2, 1] ) == [2, 3, 6]

class Test_ArrayProduct2(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert product2( [1, 2, 3, 4, 5] ) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert product2( [3, 2, 1] ) == [2, 3, 6]


class Test_ArrayProduct3(unittest.TestCase):

    def setUp(self):
        pass
    
    def test_case1(self):
        assert product3( [1, 2, 3, 4, 5] ) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert product3( [3, 2, 1] ) == [2, 3, 6]

class Test_SmallestWindow(unittest.TestCase):

    def setUp(self):
        pass
    
    def test_case1(self):
        assert window1( [3, 7, 5, 6, 9]) == (1, 3)
    
    def test_case2(self):
        assert window1( [3, 7, 5, 6, 9, 2, 3, 14, 15, 16, 17, 1.5]) == (1, 11)

class Test_MaxSubarraySum(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert max_subarray_sum1( [34, -50, 42, 14, -5, 86]) == 137
    
    def test_case2(self):
        assert max_subarray_sum1( [-5, -1, 8, -9]) == 0


class Test_SmallerCounts1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert smaller_counts1( [3, 4, 9, 6, 1]) == [1, 1, 2, 1, 0]
    
    def test_case2(self):
        assert smaller_counts1( [2, 5, 4, 7, 8]) == [0, 1, 0, 0, 0]

class Test_Rotate1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        assert rotate1(None) == None

    def test_case2(self):
        expected = [[3, 1], [4, 2]]

        assert rotate1(build_mat(2, 2)) == expected

    def test_case3(self):
         expected = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

         assert rotate1(build_mat(3, 3)) == expected

    def test_case4(self):

        expected = [[13, 9, 5, 1], [14, 10, 6, 2], [15, 11, 7, 3], [16, 12, 8, 4]]
        
        assert rotate1(build_mat(4, 4)) == expected
    
    def test_case5(self):

        expected = [[21, 16, 11, 6, 1], [22, 17, 12, 7, 2], [23, 18, 13, 8, 3], [24, 19, 14, 9, 4], [25, 20, 15, 10, 5]]

        assert rotate1(build_mat(5, 5)) == expected

class Test_Rotate2(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        assert rotate2(None) == None

    def test_case2(self):
        expected = [(3, 1), (4, 2)]

        assert rotate2(build_mat(2, 2)) == expected

    def test_case3(self):
         expected = [(7, 4, 1), (8, 5, 2), (9, 6, 3)]

         assert rotate2(build_mat(3, 3)) == expected
         
    def test_case4(self):

        expected = [(13, 9, 5, 1), (14, 10, 6, 2), (15, 11, 7, 3), (16, 12, 8, 4)]
        
        assert rotate2(build_mat(4, 4)) == expected
    
    def test_case5(self):

        expected = [(21, 16, 11, 6, 1), (22, 17, 12, 7, 2), (23, 18, 13, 8, 3), (24, 19, 14, 9, 4), (25, 20, 15, 10, 5)]

        assert rotate2(build_mat(5, 5)) == expected