import unittest

from problems.arr import majority_element

class Test_LettersNumbers2(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        arr = None
        actual = majority_element(arr)
        expected = None

        assert actual == expected

    def test_case1(self):

        arr = [1, 2, 5, 9, 5, 9, 5, 5, 5]
        actual = majority_element(arr)
        expected = 5

        assert actual == expected

    def test_case2(self):

        arr = [1, 2, 5, 9, 5, 9, 5, 5, 5, 1]
        actual = majority_element(arr)
        expected = 5

        assert actual == expected

    def test_case2(self):

        arr = [1, 2, 5, 9, 5, 9, 5, 5, 5, 1, 2]
        actual = majority_element(arr)
        expected = -1

        assert actual == expected

    def test_case3(self):

        arr = [1, 2, 5, 9, 5, 9, 5, 5, 5, 1, 2, 1, 2]
        actual = majority_element(arr)
        expected = -1

        assert actual == expected

    def test_case4(self):

        arr = [1, 2, 5, 9, 5, 9, 5, 5, 5, 1, 2, 1, 2, 5]
        actual = majority_element(arr)
        expected = -1

        assert actual == expected

    def test_case5(self):

        arr = [1, 5]
        actual = majority_element(arr)
        expected = -1

        assert actual == expected

    def test_case6(self):

        arr = [1, 5, 5]
        actual = majority_element(arr)
        expected = 5

        assert actual == expected