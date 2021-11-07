import unittest

from dcp.leetcode.arr.even_digits1 import findNumbers

class Test_EvenDigits(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        arr = [555,901,482,1771]

        actual = findNumbers(arr)
        expected = 1

        assert actual == expected

    def test_case2(self):
        
        arr = [100000]

        actual = findNumbers(arr)
        expected = 1

        assert actual == expected