import unittest

from dcp.problems.math.calculator import calculate1

class Test_Calculate1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_none(self):

        expr = None

        actual = calculate1(expr)
        expected = None

        assert actual == expected

    def test_case1(self):

        expr = "2*3+5/6*3+15"

        actual = calculate1(expr)
        expected = 23.5

        assert actual == expected

    def test_case2(self):

        expr = "2*3*2+5/6*3+15"

        actual = calculate1(expr)
        expected = 29.5

        assert actual == expected

    def test_case3(self):

        expr = "2*3*2+5/6*3+15/5"

        actual = calculate1(expr)
        expected = 17.5

        assert actual == expected

    def test_case4(self):

        expr = "1*1/1*1/1"

        actual = calculate1(expr)
        expected = 1

        assert actual == expected

    def test_case5(self):

        expr = "1+2+3+4+5/5"

        actual = calculate1(expr)
        expected = 11

        assert actual == expected