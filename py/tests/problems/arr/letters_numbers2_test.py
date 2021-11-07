import unittest

from dcp.problems.arr.letters_numbers import letters_numbers2

class Test_LettersNumbers2(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        arr = None
        actual = letters_numbers2(arr)
        expected = -1

        assert actual == expected

    def test_case1(self):

        arr = ['a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 'h', 7]
        actual = letters_numbers2(arr)
        expected = ['b', 1, 'c', 'd', 'e', 3, 5, 6]

        assert actual == expected

    def test_case2(self):

        arr = ['a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 'a', 'a', 1]

        actual = letters_numbers2(arr)
        expected = [1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a']

        assert actual == expected

    def test_case3(self):

        arr = ['a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 'a', 'a', 1]

        actual = letters_numbers2(arr)
        expected = [1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a']

        assert actual == expected

    def test_case4(self):

        arr = ['a', 1, 1, 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 'a', 'a', 1]

        actual = letters_numbers2(arr)
        expected = [1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a']

        assert actual == expected

    def test_case5(self):

        arr = ['a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 4, 7, 'a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 'h', 7]

        actual = letters_numbers2(arr)
        expected = ['b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 4, 7, 'a', 'b', 1, 'c', 'd', 'e', 3, 5, 6]

        assert actual == expected