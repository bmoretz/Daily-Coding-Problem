import unittest

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