import unittest

from leetcode.linkedlist import merge_sorted_lists

class Test_MergeSortedLists(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2 = merge_sorted_lists().build_list([1,2,4]), merge_sorted_lists().build_list([1,3,4])

        merged = merge_sorted_lists().mergeTwoLists(l1, l2)

        actual = merge_sorted_lists().to_vector(merged)

        expected = [1,1,2,3,4,4]

        assert actual == expected