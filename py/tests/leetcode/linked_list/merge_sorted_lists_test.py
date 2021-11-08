import unittest

from dcp.leetcode.linkedlist.merge_sorted_lists import mergeTwoLists, build_list, to_vector

class Test_MergeSortedLists(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2 = build_list([1,2,4]), build_list([1,3,4])

        merged = mergeTwoLists(l1, l2)

        actual = to_vector(merged)

        expected = [1,1,2,3,4,4]

        assert actual == expected
