import unittest

from dcp.problems.linkedlist.single import SLinkedList
from dcp.problems.linkedlist.alternating import alternate1, alternate2

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