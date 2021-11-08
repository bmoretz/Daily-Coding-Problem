import unittest

from problems.illuminated import read_median_data
from problems.illuminated import median_arr, median_heap

from .utility import get_test_file

class Test_MedianMaintenance(unittest.TestCase):

    def setUp(self):
        self.test_file_path = get_test_file('median-maintenance', 'problem11.3test.txt')

    def test_arr(self):

        arr = read_median_data(self.test_file_path)

        actual = median_arr(arr)
        expected = 9335

        assert actual == expected

    def test_heap(self):

        arr = read_median_data(self.test_file_path)

        actual = median_heap(arr)
        expected = 9335

        assert actual == expected