import unittest

from dcp.problems.linkedlist.single import build_list
from dcp.problems.linkedlist.is_palindrome import is_palindrome1

class Test_IsPalindrome1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert is_palindrome1(None) == None

    def test_case2(self):
        
        data = build_list(['a', 'b', 'c', 'b', 'a'])

        assert is_palindrome1(data) == True
        
    def test_case3(self):
        
        data = build_list(['a', 'b', 'b', 'a'])

        assert is_palindrome1(data) == True

    def test_case4(self):
        
        data = build_list(['a', 'b', 'c', 'a', 'a'])

        assert is_palindrome1(data) == False

    def test_case5(self):
        
        data = build_list(['a', 'a', 'c', 'b', 'a'])

        assert is_palindrome1(data) == False

    def test_case6(self):
        
        data = build_list(['b', 'b', 'c', 'b', 'a'])

        assert is_palindrome1(data) == False