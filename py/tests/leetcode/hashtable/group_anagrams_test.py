import unittest

from dcp.leetcode.hashtable.group_anagrams import groupAnagrams

class Test_GroupAnagrams(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
                
        strs = ["eat","tea","tan","ate","nat","bat"]

        actual = groupAnagrams(strs)
        expected = [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]

        assert actual == expected

    def test_case2(self):
        
        strs = [""]

        actual = groupAnagrams(strs)
        expected = [[""]]
        
        assert actual == expected

    def test_case3(self):

        strs = ["a"]

        actual = groupAnagrams(strs)
        expected = [["a"]]
        
        assert actual == expected