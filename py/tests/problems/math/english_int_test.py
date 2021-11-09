import unittest

from dcp.problems.math.english_int import english_int

class Test_EnglishInt1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        n = None

        actual = english_int(n)
        expected = None

        assert actual == expected

    def test_case1(self):

        n = 413

        actual = english_int(n)
        expected = "Four Hundred Thirteen"

        assert actual == expected

    def test_case2(self):

        n = 111

        actual = english_int(n)
        expected = "One Hundred Eleven"

        assert actual == expected


    def test_case3(self):

        n = 1234

        actual = english_int(n)
        expected = "One Thousand Two Hundred Thirty Four"

        assert actual == expected

    def test_case4(self):

        n = 2300

        actual = english_int(n)
        expected = "Two Thousand Three Hundred"

        assert actual == expected

    def test_case4(self):

        n = 0

        actual = english_int(n)
        expected = "Zero"

        assert actual == expected