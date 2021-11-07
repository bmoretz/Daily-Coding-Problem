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

from dcp.leetcode.str.find_and_replace import findReplaceString

class Test_FindAndReplace(unittest.TestCase):

    def test_case1(self):
        
        str_in = "jjievdtjfb"

        indexes, sources, targets = [4,6,1], ["md","tjgb","jf"], ["foe","oov","e"]

        actual = findReplaceString(str_in, indexes, sources, targets)

        expected = "jjievdtjfb"
        
        assert actual == expected

from dcp.leetcode.str.k_len_substrings import numKLenSubstrNoRepeats

class Test_KLenSubstrings(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        S, K = "havefunonleetcode", 5

        actual = numKLenSubstrNoRepeats(S, K)
        expected = 6

        assert actual == expected

    def test_case2(self):
        
        S, K = "bbbbabbb", 2

        actual = numKLenSubstrNoRepeats(S, K)
        expected = 2

        assert actual == expected

    def test_case3(self):

        S, K = "gdggdbjchgadcfddfahbdebjbagaicgeahehjhdfghadbcbbfhgefcihbcbjjibjdhfhbdijehhiabad", 5

        actual = numKLenSubstrNoRepeats(S, K)
        expected = 29

        assert actual == expected

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