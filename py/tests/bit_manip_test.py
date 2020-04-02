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
        M = bitarray('00000001110')

        actual = insertion1(N, M, 8, 4)
        expected = bitarray('11011100000')

        assert actual == expected