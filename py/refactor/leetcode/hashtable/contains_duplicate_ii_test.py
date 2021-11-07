import unittest

from leetcode.hashtable import contains_duplicate_ii

class Test_ContainsDuplicate_II(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        nums, k = [1,2,3,1], 3

        actual = contains_duplicate_ii.containsNearbyDuplicate(nums, k)
        expected = True

        assert actual == expected

    def test_case2(self):
        
        nums, k = [1,0,1,1], 1

        actual = contains_duplicate_ii.containsNearbyDuplicate(nums, k)
        expected = True
        
        assert actual == expected

    def test_case3(self):

        nums, k = [1,2,3,1,2,3], 2

        actual = contains_duplicate_ii.containsNearbyDuplicate(nums, k)
        expected = False
        
        assert actual == expected