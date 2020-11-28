import unittest

from py.leetcode.linkedlist import intersection

class Test_Intersection(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        headA, headB, intersect = intersection().build_list( [4,1], [5,6,1], [8,4,5] )

        actual = intersection().getIntersectionNode( headA, headB )
        expected = intersect

        assert actual == expected

from py.leetcode.linkedlist import rev_linkedlist

class Test_ReverseLinkedList(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        head = rev_linkedlist().build_list([1,2,3,4,5])

        new_list = rev_linkedlist().reverseList_iter(head)

        actual = rev_linkedlist().to_list(new_list)

        expected = [5, 4, 3, 2, 1]

        assert actual == expected

    def test_case2(self):

        head = rev_linkedlist().build_list([1,2,3,4,5])

        new_list = rev_linkedlist().reverseList_rec(head)

        actual = rev_linkedlist().to_list(new_list)

        expected = [5, 4, 3, 2, 1]

        assert actual == expected