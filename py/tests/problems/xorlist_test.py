import unittest

from py.data_structures.XORList import XorLinkedList
class Test_XORList1(unittest.TestCase):
    
    def setUp(self):
        
        self.lst = XorLinkedList()

        for index in range(5):
            self.lst.add(index)

    def test_case1(self):
    
        actual = self.lst.get(0)
        expected = 0

        assert actual == expected

    def test_case2(self):

        actual = self.lst.get(4)
        expected = 4

        assert actual == expected

    def test_case3(self):

        actual = self.lst.get(2)
        expected = 2

        assert actual == expected

    def test_case4(self):

        actual = self.lst.get(3)
        expected = 3

        assert actual == expected