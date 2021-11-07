import unittest

from dcp.leetcode.linkedlist.double_linked_list import DoubleLinkedList

class Test_DoubleLinkedList(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        dl = DoubleLinkedList()

        dl.addAtHead(1)
        dl.addAtTail(3)
        dl.addAtIndex(1, 2)

        assert dl.get(0) == 1
        assert dl.get(1) == 2
        assert dl.get(2) == 3

        dl.deleteAtIndex(1)

        assert dl.get(0) == 1
        assert dl.get(1) == 3

        dl.deleteAtIndex(0)

        assert dl.get(0) == 3

    def test_case2(self):

        dl = DoubleLinkedList()

        dl.addAtHead(7)
        dl.addAtTail(7)
        dl.addAtHead(9)
        dl.addAtTail(8)
        dl.addAtHead(6)
        dl.addAtHead(0)

        assert dl.get(0) == 0
        assert dl.get(1) == 6
        assert dl.get(2) == 9
        assert dl.get(3) == 7
        assert dl.get(4) == 7
        assert dl.get(5) == 8

        dl.addAtHead(0)

        assert dl.get(2) == 6
        assert dl.get(5) == 7

        dl.addAtTail(4)

        assert dl.get(7) == 4