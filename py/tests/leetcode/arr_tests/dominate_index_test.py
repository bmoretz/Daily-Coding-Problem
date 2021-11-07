import unittest

from dcp.leetcode.arr import dominate_index

class Test_DominantIndex(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        actual = dominate_index.dominantIndex([3, 6, 1, 0])
        expected = 1

        assert actual == expected

    def test_case2(self):
        
        actual = dominate_index.dominantIndex([1, 2, 3, 4])
        expected = -1

        assert actual == expected