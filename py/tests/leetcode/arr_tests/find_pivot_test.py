import unittest

from dcp.leetcode.arr import find_pivot

class Test_FindPivot(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        actual = find_pivot.pivotIndex([1,7,3,6,5,6])
        expected = 3

        assert actual == expected