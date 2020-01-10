import unittest

from problems.str import anagram1
from problems.str import palindrome1, palindrome2
from problems.str import is_palindrome

class Test_Anagram1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert anagram1( "abxaba", "ab" ) == [0, 3, 4]

    def test_case2(self):
        assert anagram1( "abba", "ab" ) == [0, 2]

class Test_Palindrome(unittest.TestCase):

    def setUp(self):
        pass

    def test_pal1(self):
        assert is_palindrome("codeedoc") == True

    def test_pal2(self):
        assert is_palindrome("code") == False


class Test_Palindrome1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert palindrome1( ["code", "edoc", "da", "d"] ) == [(0, 1), (1, 0), (2, 3)]

    def test_case2(self):
        assert palindrome1( ["code", "edoc", "da", "d"] ) == [(0, 1), (1, 0), (2, 3)]

class Test_Palindrome2(unittest.TestCase):
   
    def setUp(self):
        pass
    
    def test_case1(self):
        assert palindrome2( ["code", "edoc", "da", "d"] ) == [(0, 1), (1, 0), (2, 3)]

    def test_case2(self):
        assert palindrome2( ["code", "edoc", "da", "d"] ) == [(0, 1), (1, 0), (2, 3)]