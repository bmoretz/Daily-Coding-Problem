import unittest

from dcp.problems.hashtable.pair_sum import pair_sum1

class Test_PairSum(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        arr = None

        actual = pair_sum1(arr, 4)
        expected = None

        assert actual == expected

    def test_case1(self):

        arr = [4, 1, 2, 7, 12, 9, 5]

        actual = pair_sum1(arr, 6)
        expected = {(4, 2), (5, 1)}

    def test_case2(self):

        arr = [4, 1, 2, 7, 12, 9, 5, 16, 0, 9]

        actual = pair_sum1(arr, 4)
        expected = {(4, 0), (2, 2)}

    def test_case3(self):

        arr = [4, 1, 2, 7, 12, 9, 5, 16, 0, 9]

        actual = pair_sum1(arr, 8)
        expected = {(1, 7)}

    def test_case4(self):

        arr = [4, 1, 2, 7, 12, 9, 5, 16, 0, 9, 4]

        actual = pair_sum1(arr, 8)
        expected = {(4, 4), (1, 7)}

    def test_case5(self):

        arr = [4, 1, 2, 7, 12, 9, 5, 16, 0, 9, 4]

        actual = pair_sum1(arr, 9)
        expected = {(9, 0), (4, 5), (2, 7)}
