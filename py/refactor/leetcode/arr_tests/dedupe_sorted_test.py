import unittest

from leetcode.arr import dedupe_sorted

class Test_DedupeSorted(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        arr = [0,0,1,1,1,2,2,3,3,4]

        actual = dedupe_sorted().removeDuplicates(arr)
        expected = 5

        assert actual == expected

    def test_case2(self):
        
        arr = [0,1,1,2]

        actual = dedupe_sorted().removeDuplicates(arr)
        expected = 3

        assert actual == expected