import unittest

from dcp.problems.bit_manip.bin_to_str import binrep1

class Test_BinaryString1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        actual = binrep1(.729)

        expected = ".10111010100111111"

        assert actual == expected

    def test_case2(self):
        actual = binrep1(.828)

        expected = ".11010011111101111"

        assert actual == expected

    def test_case3(self):
        actual = binrep1(.72)

        expected = ".10111000010100011"

        assert actual == expected

    def test_case4(self):
        actual = binrep1(.90210)

        expected = ".111001101111"

        assert actual == expected

    def test_case5(self):
        actual = binrep1(.0129214)

        expected = ".00000011010011101"

        assert actual == expected