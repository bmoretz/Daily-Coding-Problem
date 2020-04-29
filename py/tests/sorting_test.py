import unittest

from py.problems.sorting import merge_sort1
class Test_MergeSort1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):

        values = [5, 4, 1, 8, 7, 2, 6, 3, 9]

        actual = merge_sort1(values)

        expected = sorted(values)
        
        assert actual == expected

    def test_case2(self):

        values = [23, 44, 19, 2, 17, 14, 16, 31]

        actual = merge_sort1(values)

        expected = sorted(values)
        
        assert actual == expected

    def test_case3(self):

        values = [1, 2, 3]

        actual = merge_sort1(values)

        expected = sorted(values)
        
        assert actual == expected

    def test_case4(self):

        values = [-1, -2, -3, -4, -3]

        actual = merge_sort1(values)

        expected = sorted(values)
        
        assert actual == expected

    def test_case5(self):

        values = [23, 44, 19, 2, 17, 14, 16, 31]

        actual = merge_sort1(values)

        expected = sorted(values)
        
        assert actual == expected

from py.problems.sorting import sorted_merge1
class Test_SortedMerge1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        A = [None]
        B = [None]

        A = A + [None] * len(B)

        actual = sorted_merge1(A, B)

        expected = [None, None]
        
        assert actual == expected

    def test_empty(self):

        A = None
        B = None

        actual = sorted_merge1(A, B)

        expected = [None, None]
        
        assert actual == expected

    def test_case1(self):

        A = [1, 3, 5, 9, 10, 15]
        B = [2, 4, 6, 8, 12, 13]

        A = A + [None] * len(B)

        actual = sorted_merge1(A, B)

        expected = [1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 13, 15]
        
        assert actual == expected

    def test_case2(self):

        A = [3, 8, 9]
        B = [0, 1, 2]

        A = A + [None] * len(B)

        actual = sorted_merge1(A, B)

        expected = [0, 1, 2, 3, 8, 9]
        
        assert actual == expected

    def test_case3(self):

        A = [0, 1, 2]
        B = [3, 8, 9]

        A = A + [None] * len(B)

        actual = sorted_merge1(A, B)

        expected = [0, 1, 2, 3, 8, 9]
        
        assert actual == expected

    