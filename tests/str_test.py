import unittest

from problems.str import anagram1
from problems.str import is_palindrome, palindrome1, palindrome2
from problems.str import zigzag1
from problems.str import is_unique1, is_unique2
from problems.str import is_permutation
from problems.str import urlify1, urlify2
from problems.str import is_palindrome_perm1
from problems.str import is_one_away1

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

zigzag_out = """
t     a     g
 h   s z   a 
  i i   i z  
   s     g   
"""

class Test_Zigzag1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert zigzag1("thisisazigzag", 4) == zigzag_out

class Test_IsUnique1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert is_unique1("abcdefg") == True

    def test_case2(self):
        assert is_unique1("abcdeffg") == False
    
    def test_case3(self):
        assert is_unique1(None) == False

class Test_IsUnique2(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert is_unique1("abcdefg") == True

    def test_case2(self):
        assert is_unique1("abcdeffg") == False
    
    def test_case3(self):
        assert is_unique1(None) == False

class Test_IsPermutation(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert is_permutation("abc", "bca") == True

    def test_case2(self):
        assert is_permutation("abc", "bce") == False
    
    def test_case3(self):
        assert is_permutation(None, None) == False

class Test_Urlify1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert urlify1(None) == None

    def test_case2(self):
        assert urlify1("http://www.test.com/s/this is a web call/to a svc/") == 'http://www.test.com/s/this%20is%20a%20web%20call/to%20a%20svc/'
    
    def test_case3(self):
        assert urlify1('a a') == 'a%20a'

    def test_case4(self):
        assert urlify1('Mr John Smith') == 'Mr%20John%20Smith'

class Test_Urlify2(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert urlify2(None) == None

    def test_case2(self):
        assert urlify2("http://www.test.com/s/this is a web call/to a svc/") == 'http://www.test.com/s/this%20is%20a%20web%20call/to%20a%20svc/'
    
    def test_case3(self):
        assert urlify2('a a') == 'a%20a'
    
    def test_case4(self):
        assert urlify2('Mr John Smith') == 'Mr%20John%20Smith'

class Test_IsPalindromePerm(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert is_palindrome_perm1(None) == False

    def test_case2(self):
        assert is_palindrome_perm1('Tact Coa') == True

    def test_case3(self):
        assert is_palindrome_perm1('aba') == True
    
    def test_case4(self):
        assert is_palindrome_perm1('ab') == True

    def test_case5(self):
        assert is_palindrome_perm1('abcd') == False

    def test_case6(self):
        assert is_palindrome_perm1('tactcoapapa') == True

class Test_IsOneAway1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert is_one_away1(None) == False

    def test_case2(self):
        assert is_one_away1('pale', 'ple') == True

    def test_case3(self):
        assert is_one_away1('pales', 'pale') == True
    
    def test_case4(self):
        assert is_one_away1('pale', 'bale') == True

    def test_case5(self):
        assert is_one_away1('pale', 'bake') == False

    def test_case6(self):
        assert is_one_away1('pale', 'apaled') == False