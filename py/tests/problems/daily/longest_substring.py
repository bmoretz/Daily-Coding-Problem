import unittest

from dcp.problems.daily.longest_substring import longest_substring1

class Test_LongestSubstring1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):      
        assert longest_substring1('abcba', 2) == 3

from dcp.problems.daily.longest_substring import longest_substring2

class Test_LongestSubstring2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):      
        assert longest_substring2('abcba', 2) == 3