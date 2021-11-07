import unittest

from problems.arr import max_subarray_sum1

class Test_MaxSubarraySum(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert max_subarray_sum1( [34, -50, 42, 14, -5, 86]) == 137
    
    def test_case2(self):
        assert max_subarray_sum1( [-5, -1, 8, -9]) == 0