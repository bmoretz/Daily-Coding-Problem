import unittest

from problems.illuminated import read_two_sum_data
from problems.illuminated import two_sum_brute, two_sum_hash, two_sum_bin

from .utility import get_test_file

class Test_TwoSum(unittest.TestCase):

    def setUp(self):
        self.test_file_path = get_test_file('two-sum', 'problem12.4test.txt')

    def test_brute(self):

        arr = read_two_sum_data(self.test_file_path)

        lower, upper = 3, 10

        actual = two_sum_brute(arr, lower, upper)
        expected = 8

        assert actual == expected

    def test_hash(self):

        arr = read_two_sum_data(self.test_file_path)

        lower, upper = 3, 10

        actual = two_sum_hash(arr, lower, upper)
        expected = 8

        assert actual == expected

    def test_bin(self):

        arr = read_two_sum_data(self.test_file_path)

        lower, upper = 3, 10

        actual = two_sum_bin(arr, lower, upper)
        expected = 8

        assert actual == expected