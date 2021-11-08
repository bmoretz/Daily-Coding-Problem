import unittest

from dcp.problems.linkedlist.single import SLinkedList
from dcp.problems.linkedlist.add_numbers import add_numbers1, add_numbers2

class Test_SingleLinkedListAdd1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2 = SLinkedList(), SLinkedList()

        for x in [9, 9]: l1.push_back(x)
        for x in [5, 2]: l2.push_back(x)

        result = add_numbers1(l1, l2)
        
        assert result.elements() == [4, 2, 1]

class Test_SingleLinkedListAdd2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2, result = SLinkedList(), SLinkedList(), SLinkedList()

        for x in [9, 9]: l1.push_back(x)
        for x in [5, 2]: l2.push_back(x)

        result.head = add_numbers2(l1.head, l2.head)
        
        assert result.elements() == [4, 2, 1]