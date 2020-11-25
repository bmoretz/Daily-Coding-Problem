import unittest

from py.leetcode.linkedlist import intersection

class Test_SortedSquares(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        headA, headB, intersect = intersection().build_list( [4,1], [5,6,1], [8,4,5] )

        actual = intersection().getIntersectionNode( headA, headB )
        expected = intersect

