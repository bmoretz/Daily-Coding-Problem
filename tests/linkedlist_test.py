import unittest

from problems.linkedlist import Node, SLinkedList

class Test_SingleLinkedList(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        sl = SLinkedList()

        for d in range(0, 10):
            sl.push_back(d)
        
        sl.reverse()

        assert sl.elements() == [9, 8, 7, 6, 5, 4, 3, 2, 1]