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