
import unittest

from py.leetcode.hashtable import is_isomorphic

class Test_IsIsomorphic(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        s, t = "egg", "add"
        
        actual = is_isomorphic.isIsomorphic(s, t)
        expected = True

        assert actual == expected

    def test_case2(self):
        
        s, t = "foo", "bar"
        
        actual = is_isomorphic.isIsomorphic(s, t)
        expected = False
        
        assert actual == expected

    def test_case3(self):
        
        s, t = "paper", "title"
        
        actual = is_isomorphic.isIsomorphic(s, t)
        expected = True
        
        assert actual == expected