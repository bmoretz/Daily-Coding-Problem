import unittest

from dcp.problems.math.sum_swap import sum_swap

class Test_SumSwap1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_none(self):

        arr = None

        actual = sum_swap(arr, arr)
        expected = None

        assert actual == expected

    def test_case1(self):

        arr1, arr2 = [4, 1, 2, 1, 1, 2], [3, 6, 3, 3]

        actual = sum_swap(arr1, arr2)
        expected = {(4, 6), (1, 3)}

        assert actual == expected

    def test_case2(self):

        arr1, arr2 = [4, 1, 2, 1, 1, 2], [3, 6, 3, 3, 2]

        actual = sum_swap(arr1, arr2)
        expected = set()

        assert actual == expected

    def test_case3(self):

        arr1, arr2 = [4, 1, 2, 1, 1, 2], [3, 6, 3, 3, 5, 1]

        actual = sum_swap(arr1, arr2)
        expected = {(1, 6)}

        assert actual == expected

    def test_case4(self):

        arr1, arr2 = [4, 1, 2, 1, 1, 2, 4, 2, 1], [1, 6, 2, 3, 5, 1]

        actual = sum_swap(arr1, arr2)
        expected = {(1, 1), (2, 2)}

        assert actual == expected

    def test_case5(self):

        arr1, arr2 = [4, 1, 2, 1, 1, 2, 4, 2, 1, 2], [1, 6, 2, 3, 5, 1]

        actual = sum_swap(arr1, arr2)
        expected = {(2, 1), (4, 3)}

        assert actual == expected