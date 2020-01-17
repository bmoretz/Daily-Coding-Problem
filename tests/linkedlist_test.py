import unittest

from problems.linkedlist import Node, SLinkedList
from problems.linkedlist import add_numbers1, add_numbers2
from problems.linkedlist import alternate1

class Test_SingleLinkedList(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        sl = SLinkedList()

        for d in range(0, 10):
            sl.push_back(d)
        
        sl.reverse()

        assert sl.elements() == [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]

class Test_SingleLinkedListReverse1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        sl = SLinkedList()

        for d in range(0, 10):
            sl.push_back(d)
        
        sl.reverse()

        assert sl.elements() == [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]

class Test_SingleLinkedListAdd1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2 = SLinkedList(), SLinkedList()

        l1.push_back(9)
        l1.push_back(9)

        l2.push_back(5)
        l2.push_back(2)

        result = add_numbers1(l1, l2)
        
        assert result.elements() == [4, 2, 1]

class Test_SingleLinkedListAdd2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2, result = SLinkedList(), SLinkedList(), SLinkedList()

        l1.push_back(9)
        l1.push_back(9)

        l2.push_back(5)
        l2.push_back(2)

        result.head = add_numbers2(l1.head, l2.head)
        
        assert result.elements() == [4, 2, 1]

class Test_SingleLinkedListAlt1(unittest.TestCase):
    
    def setUp(self):
        pass

    '''Case: 1, 2, 3, 4, 5'''
    def test_case1(self):

        items = SLinkedList()

        for index in range(1, 6):
            items.push_back(index)

        result = alternate1(items)

        assert result.elements() == [1, 3, 2, 5, 4]