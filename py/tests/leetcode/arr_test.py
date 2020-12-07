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

from py.leetcode.arr import find_pivot

class Test_FindPivot(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        actual = find_pivot.pivotIndex([1,7,3,6,5,6])
        expected = 3

        assert actual == expected

from py.leetcode.arr import dominate_index

class Test_DominantIndex(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        actual = dominate_index.dominantIndex([3, 6, 1, 0])
        expected = 1

        assert actual == expected

    def test_case2(self):
        
        actual = dominate_index.dominantIndex([1, 2, 3, 4])
        expected = -1

        assert actual == expected

from py.leetcode.arr import plus_one

class Test_PlusOne(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        actual = plus_one.plusOne([4,3,2,1])
        expected = [4,3,2,2]

        assert actual == expected

    def test_case2(self):
        
        actual = plus_one.plusOne([4,3,3,9])
        expected = [4,3,4,0]

        assert actual == expected

    def test_case3(self):
        
        actual = plus_one.plusOne([9])
        expected = [1,0]

        assert actual == expected