import unittest

from problems.illuminated import count_inversions

class Test_CountInversions(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        arr = [1, 3, 5, 2, 4, 6]

        actual = count_inversions(arr)
        expected = 3

        assert actual == expected

    def test_case2(self):

        arr = [1, 3, 5, 2, 4, 6, 4]

        actual = count_inversions(arr)
        expected = 5

        assert actual == expected

    def test_case3(self):

        arr = [1, 5, 3, 2, 4, 6]

        actual = count_inversions(arr)
        expected = 4

        assert actual == expected

    def test_case4(self):

        arr = [1, 5, 3, 2, 1]

        actual = count_inversions(arr)
        expected = 6

        assert actual == expected

    def test_case4(self):

        arr = [1, 3]

        actual = count_inversions(arr)
        expected = 0

        assert actual == expected