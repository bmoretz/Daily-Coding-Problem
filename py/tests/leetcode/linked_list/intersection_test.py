import unittest

from dcp.leetcode.linkedlist.intersection import getIntersectionNode

class Test_Intersection(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        from dcp.leetcode.linkedlist.intersection import build_list

        headA, headB, intersect = build_list([4,1], [5,6,1], [8,4,5])

        actual = getIntersectionNode(headA, headB)
        expected = intersect

        assert actual == expected