import unittest

from dcp.leetcode.arr import min_size_subarray_sum

class Test_MinSizeSubarraySum(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        s, n = 7, [2,3,1,2,4,3]
        
        actual = min_size_subarray_sum.minSubArrayLen(s, n)
        expected = 2

        assert actual == expected

    def test_case2(self):
        
        s, n = 20, [2,3,1,2,4,3]
        
        actual = min_size_subarray_sum.minSubArrayLen(s, n)
        expected = 0

        assert actual == expected