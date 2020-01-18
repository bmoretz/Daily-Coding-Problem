import unittest

from problems.linkedlist import Node, SLinkedList
from problems.linkedlist import add_numbers1, add_numbers2
from problems.linkedlist import alternate1, alternate2
from problems.linkedlist import intersect1, intersect2

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

    def test_case1(self):

        items = SLinkedList()

        for index in range(1, 6):
            items.push_back(index)

        result = alternate1(items)

        assert result.elements() == [1, 3, 2, 5, 4]

class Test_SingleLinkedListAlt2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        items = SLinkedList()

        for index in range(1, 6):
            items.push_back(index)

        result = alternate2(items)

        assert result.elements() == [1, 3, 2, 5, 4]

class Test_SingleLinkedListIntersect1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        list1, list2 = SLinkedList(), SLinkedList()

        list1.push_back(3)
        list1.push_back(7)
        list1.push_back(8)
        list1.push_back(10)

        list2.push_back(99)
        list2.push_back(1)
        list2.push_back(8)
        list2.push_back(10)

        assert intersect1(list1, list2) == 8

class Test_SingleLinkedListIntersect2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        list1, list2 = SLinkedList(), SLinkedList()

        list1.push_back(3)
        list1.push_back(7)
        list1.push_back(8)
        list1.push_back(10)

        list2.push_back(99)
        list2.push_back(1)
        list2.push_back(8)
        list2.push_back(10)
        
        result = intersect2(list1, list2)

        assert result.data == 8