import unittest

from dcp.leetcode.arr.dedupe_sorted import removeDuplicates

class Test_DedupeSorted(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        arr = [0,0,1,1,1,2,2,3,3,4]

        actual = removeDuplicates(arr)
        expected = 5

        assert actual == expected

    def test_case2(self):
        
        arr = [0,1,1,2]

        actual = removeDuplicates(arr)
        expected = 3

        assert actual == expected