import unittest

from leetcode.arr import even_digits1

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