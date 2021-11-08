import unittest

from dcp.problems.arr.smallest_difference import smallest_difference2

class Test_SmallestDifference2(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        arr1 = []
        arr2 = None

        actual = smallest_difference2(arr1, arr2)
        expected = None

        assert actual == expected

    def test_case1(self):
        
        arr1 = [1, 3, 15, 11, 2]
        arr2 = [23, 127, 235, 19, 8]

        actual = smallest_difference2(arr1, arr2)
        expected = (11, 8, 3)

        assert actual == expected

    def test_case2(self):
        
        arr1 = [190, 73, 294, 240, 29]
        arr2 = [89, 117, 224, 30, 152]

        actual = smallest_difference2(arr1, arr2)
        expected = (30, 29, 1)

        assert actual == expected

    def test_case3(self):
        
        arr1 = [296, 254, 181, 12, 62]
        arr2 = [15, 4, 255, 110, 237]

        actual = smallest_difference2(arr1, arr2)
        expected = (255, 254, 1)

        assert actual == expected