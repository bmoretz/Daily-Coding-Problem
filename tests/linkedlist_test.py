import unittest

from problems.linkedlist import Node, SLinkedList
from problems.linkedlist import add_numbers

class Test_SingleLinkedListReverse(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        sl = SLinkedList()

        for d in range(0, 10):
            sl.push_back(d)
        
        sl.reverse()

        assert sl.elements() == [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]

class Test_SingleLinkedListAdd(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2 = SLinkedList(), SLinkedList()

        l1.push_back(9)
        l1.push_back(9)

        l2.push_back(5)
        l2.push_back(2)

        result = add_numbers(l1, l2)
        
        print(result.elements())

        assert result.elements() == [4, 2, 1]