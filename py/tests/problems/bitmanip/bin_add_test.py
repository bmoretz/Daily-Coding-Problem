import unittest

from dcp.problems.bit_manip.bin_add import bin_add1

class Test_BinAdd1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        a, b = 1, None

        actual = bin_add1(a, b)
        expected = None

        assert actual == None

    def test_case1(self):

        a = 6 # 0110
        b = 6 # 0110

        actual = bin_add1(a, b)
        expected = 12 # 1100

        assert actual == expected

    def test_case2(self):

        a = 9 # 1001
        b = 7 # 0111

        actual = bin_add1(a, b)
        expected = 16 # 10000

        assert actual == expected

    def test_case3(self):

        a = 4 # 0100
        b = 6 # 0011

        actual = bin_add1(a, b)
        expected = 10 # 1010

        assert actual == expected

    def test_case4(self):

        a = 658 # 1010010010
        b = 326 # 0101000110

        actual = bin_add1(a, b)
        expected = 984 # 1111011000

        assert actual == expected

    def test_case5(self):

        a = 9101 # 10001110001101
        b = 43 # 101011

        actual = bin_add1(a, b)
        expected = 9192 # 10001111101000

        assert actual == expected