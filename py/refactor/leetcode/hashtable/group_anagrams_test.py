import unittest

from leetcode.hashtable import group_anagrams

class Test_GroupAnagrams(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
                
        strs = ["eat","tea","tan","ate","nat","bat"]

        actual = group_anagrams().groupAnagrams(strs)
        expected = [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]

        assert actual == expected

    def test_case2(self):
        
        strs = [""]

        actual = group_anagrams().groupAnagrams(strs)
        expected = [[""]]
        
        assert actual == expected

    def test_case3(self):

        strs = ["a"]

        actual = group_anagrams().groupAnagrams(strs)
        expected = [["a"]]
        
        assert actual == expected