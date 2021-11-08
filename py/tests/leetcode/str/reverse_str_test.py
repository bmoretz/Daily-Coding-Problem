import unittest

from dcp.leetcode.str.reverse_string import reverseString

class Test_ReverseString(unittest.TestCase):

    def test_case1(self):
        
        actual = ["h","e","l","l","o"]

        reverseString(actual)
        
        expected = ["o","l","l","e","h"]

        assert actual == expected

    def test_case2(self):
        
        actual = ["h","e"]

        reverseString(actual)

        expected = ["e", "h"]

        assert actual == expected

    def test_case3(self):
        
        actual = ["h","e","i"]

        reverseString(actual)
        
        expected = ["i","e","h"]

        assert actual == expected