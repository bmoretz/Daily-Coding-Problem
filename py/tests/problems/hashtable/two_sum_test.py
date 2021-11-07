import unittest

from dcp.problems.hashtable.two_sum import two_sum1

class Test_TwoSum1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        arr, k = [10, 15, 3, 7], 17

        assert two_sum1(arr, k) == True