import unittest
        
from dcp.problems.math.contiguous_sequence import contiguous_seq1

class Test_ContiguousSeq1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_none(self):

        arr = None

        actual = contiguous_seq1(arr)
        expected = None

        assert actual == expected

    def test_case1(self):

        arr = [2, -8, 3, -2, 4, -10]

        actual = contiguous_seq1(arr)
        expected = 5

        assert actual == expected
    
    def test_case2(self):

        arr = [2, -8, 3, -7, 4, -10]

        actual = contiguous_seq1(arr)
        expected = None

        assert actual == expected

    def test_case3(self):

        arr = [2, -8, 3, -7, 4, -10, 12, -3]

        actual = contiguous_seq1(arr)
        expected = 9

        assert actual == expected

    def test_case4(self):

        arr = [2, -8, 3, -7, 4, -10, 12, -2, 4, -1]

        actual = contiguous_seq1(arr)
        expected = 13

        assert actual == expected

    def test_case5(self):

        arr = [2, -2, 3, -7, 4, -10, 7, -2, 4, -1]

        actual = contiguous_seq1(arr)
        expected = 8

        assert actual == expected