import unittest

from py.leetcode.arr import duplicate_zeros

class Test_DuplicateZeros(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        actual = [1,0,2,3,0,4,5,0]

        duplicate_zeros().duplicateZeros(actual)

        expected = [1,0,0,2,3,0,0,4]

        assert actual == expected

    def test_case2(self):
        
        actual = [0,0,0,0,0,0,0]

        duplicate_zeros().duplicateZeros(actual)

        expected = [0,0,0,0,0,0,0]

        assert actual == expected

from py.leetcode.arr import even_digits1

class Test_EvenDigits(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        arr = [555,901,482,1771]

        actual = even_digits1().findNumbers(arr)
        expected = 1

        assert actual == expected

    def test_case2(self):
        
        arr = [100000]

        actual = even_digits1().findNumbers(arr)
        expected = 1

        assert actual == expected

from py.leetcode.arr import sorted_squares

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

from py.leetcode.arr import dedupe_sorted

class Test_DedupeSorted(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        arr = [0,0,1,1,1,2,2,3,3,4]

        actual = dedupe_sorted().removeDuplicates(arr)
        expected = 5

        assert actual == expected

    def test_case2(self):
        
        arr = [0,1,1,2]

        actual = dedupe_sorted().removeDuplicates(arr)
        expected = 3

        assert actual == expected

