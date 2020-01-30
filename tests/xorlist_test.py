import unittest

from problems.xorlist import Node, XorLinkedList

class Test_XORList1(unittest.TestCase):
    
    def setUp(self):
        self._lst = XorLinkedList()

        for index in range(5):
            self._lst.add(Node(index))

    def test_case1(self):       
        assert self._lst.get(4) == self._lst.tail

    def test_case2(self):
        assert self._lst.get(0) == self._lst.head