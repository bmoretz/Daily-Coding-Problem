import unittest

from dcp.problems.arr.smallest_k import smallest_k2

class Test_SmallestK1(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        arr = None
        k = 3

        actual = smallest_k2(arr, k)
        expected = None

        assert actual == expected

    def test_case1(self):

        arr = [2, 1, 5, 7, 9, 11, 3, 0, 8]
        k = 3

        actual = smallest_k2(arr, k)
        expected = [0, 1, 2]

        assert actual == expected

    def test_case2(self):

        arr = [2, 1, 5, 7, 9, 11, 3, 0, 8, 15, -1]
        k = 3
        
        actual = smallest_k2(arr, k)
        expected = [-1, 0, 1]

        assert actual == expected

    def test_case3(self):

        arr = [2, 1, 5, 7, 9, 11, 3, 0, 8, 15, -1, 18]
        k = 4
        
        actual = smallest_k2(arr, k)
        expected = [-1, 0, 1, 2]

        assert actual == expected

    def test_case4(self):

        arr = [2, 1, 5, 7, 9, 11, 3, 0, 8, 15, -1, 18]
        k = 4
        
        actual = smallest_k2(arr, k)
        expected = [-1, 0, 1, 2]

        assert actual == expected

    def test_case5(self):

        arr = [2, 1, 5, 7, 9, 11, 3, 0, 8, 15, -1, 18]
        k = 5
        
        actual = smallest_k2(arr, k)
        expected = [-1, 0, 1, 2, 3]

        assert actual == expected