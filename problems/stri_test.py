import unittest

from stri import anagram1

class Test_Anagram1(unittest.TestCase):
    
    _inst = anagram1
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert self._inst.func( self, "abxaba", "ab" ) == [0, 3, 4]

    def test_case2(self):
        assert self._inst.func( self, "abba", "ab" ) == [0, 2]