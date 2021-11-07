import unittest

from leetcode.linkedlist import rev_linkedlist

class Test_ReverseLinkedList(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        head = rev_linkedlist().build_list([1,2,3,4,5])

        new_list = rev_linkedlist().reverseList_iter(head)

        actual = rev_linkedlist().to_list(new_list)

        expected = [5, 4, 3, 2, 1]

        assert actual == expected