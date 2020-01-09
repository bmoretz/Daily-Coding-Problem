import unittest

from problems.str import anagram1, palindrome1

class Test_Anagram1(unittest.TestCase):
    
    _inst = anagram1
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert self._inst.func( self, "abxaba", "ab" ) == [0, 3, 4]

    def test_case2(self):
        assert self._inst.func( self, "abba", "ab" ) == [0, 2]

class Test_Palindrome1(unittest.TestCase):
    
    _inst = palindrome1
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert self._inst.func( ["code", "edoc", "da", "d"] ) == [(0, 1), (1, 0), (2, 3)]

    def test_case2(self):
        assert self._inst.func( ["code", "edoc", "da", "d"] ) == [(0, 1), (1, 0), (2, 3)]

    def test_pal1(self):
        assert self._inst._is_palindrome("codeedoc") == True

    def test_pal2(self):
        assert self._inst._is_palindrome("code") == False
