import unittest

from py.problems.sorting import merge_sort1
class Test_BitFlip2(unittest.TestCase):
    
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