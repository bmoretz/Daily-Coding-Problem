import unittest

from dcp.leetcode.str.longest_common_prefix import longestCommonPrefix

class Test_LongestCommonPrefix(unittest.TestCase):

    def test_case1(self):
        
        input1 = ["flower","flow","flight"]

        actual = longestCommonPrefix(input1)
        expected = "fl"

        assert actual == expected
        
    def test_case2(self):
        
        input1 = ["ab", "a"]

        actual = longestCommonPrefix(input1)
        expected = "a"

        assert actual == expected

    def test_case3(self):
        
        input1 = ["dog","racecar","car"]

        actual = longestCommonPrefix(input1)
        expected = ""

        assert actual == expected