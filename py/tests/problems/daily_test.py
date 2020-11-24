import unittest

from py.problems.daily import first_missing1
class Test_FirstMissing1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        assert first_missing1([3, 4, -1, 1]) == 2

    def test_case2(self):
        assert first_missing1([1, 2, 0]) == 3

    def test_case3(self):
        assert first_missing1([1, 2, 2, 1, 0]) == 3

from py.problems.daily import first_missing2
class Test_FirstMissing2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):        
        assert first_missing2([3, 4, -1, 1]) == 2

    def test_case2(self):
        assert first_missing2([1, 2, 0]) == 3

    def test_case3(self):
        assert first_missing2([1, 2, 2, 1, 0]) == 3

from py.problems.daily import car, cons, cdr
class Test_Construct1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        assert car(cons(3, 4)) == 3

    def test_case2(self):
        assert cdr(cons(3, 4)) == 4

from py.problems.daily import num_encoding1
class Test_NumEncodings(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):      
        assert num_encoding1('111') == 3

    def test_case2(self):
        assert num_encoding1('011') == 0

    def test_case3(self):
        assert num_encoding1('602') == 0

from py.problems.daily import longest_substring1
class Test_LongestSubstring1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):      
        assert longest_substring1('abcba', 2) == 3

from py.problems.daily import longest_substring2
class Test_LongestSubstring2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):      
        assert longest_substring2('abcba', 2) == 3