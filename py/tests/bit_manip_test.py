import unittest

from bitarray import bitarray

from py.problems.bit_manip import insertion1
class Test_Insertion1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        N = bitarray('10000000000')
        M = bitarray('00000010011')

        actual = insertion1(N, M, 6, 2)
        expected = bitarray('10001001100')

        assert actual == expected

    def test_case2(self):

        N = bitarray('10000000000')
        M = bitarray('00000001111')

        actual = insertion1(N, M, 8, 4)
        expected = bitarray('10011110000')

        assert actual == expected

    def test_case3(self):

        N = bitarray('11000000000')
        M = bitarray('00000001110')

        actual = insertion1(N, M, 8, 4)
        expected = bitarray('11011100000')

        assert actual == expected

    def test_case4(self):

        N = bitarray('11000000000')
        M = bitarray('00000011110')

        actual = insertion1(N, M, 8, 4)
        expected = bitarray('11111100000')

        assert actual == expected

from py.problems.bit_manip import binrep1
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