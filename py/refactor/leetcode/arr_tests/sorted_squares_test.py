import unittest

from leetcode.arr import sorted_squares

class Test_SortedSquares(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        arr = [-4, -1, 0, 3, 10]

        actual = sorted_squares().sortedSquares(arr)
        expected = [0, 1, 9, 16, 100]

        assert actual == expected

    def test_case2(self):
        
        arr = [-7, -3, 2, 3, 11]

        actual = sorted_squares().sortedSquares(arr)
        expected = [4, 9, 9, 49, 121]

        assert actual == expected