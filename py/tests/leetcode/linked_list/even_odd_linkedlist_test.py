import unittest

from dcp.leetcode.linkedlist.even_odd_linkedlist import oddEvenList, build_list, to_list

class Test_EvenOddLinkedList(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        head = build_list([1,2,3,4,5])

        new_list = oddEvenList(head)

        actual = to_list(new_list)

        expected = [1, 3, 5, 2, 4]

        assert actual == expected

    def test_case2(self):
        
        head = build_list([1,2,3,4,5])

        new_list = oddEvenList(head)

        actual = to_list(new_list)

        expected = [1, 3, 5, 2, 4]

        assert actual == expected