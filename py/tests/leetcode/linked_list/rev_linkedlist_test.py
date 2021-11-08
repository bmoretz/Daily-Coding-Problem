import unittest

from dcp.leetcode.linkedlist.rev_linkedlist import reverseList_iter, reverseList_rec, build_list, to_list

class Test_ReverseLinkedList(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        head = build_list([1,2,3,4,5])

        new_list = reverseList_iter(head)

        actual = to_list(new_list)

        expected = [5, 4, 3, 2, 1]

        assert actual == expected