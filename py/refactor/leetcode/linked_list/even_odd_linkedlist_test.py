import unittest

from leetcode.linkedlist import even_odd_linkedlist

class Test_EvenOddLinkedList(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        head = even_odd_linkedlist().build_list([1,2,3,4,5])

        new_list = even_odd_linkedlist().oddEvenList(head)

        actual = even_odd_linkedlist().to_list(new_list)

        expected = [1, 3, 5, 2, 4]

        assert actual == expected

    def test_case2(self):

        head = even_odd_linkedlist().build_list([1,2,3,4,5])

        new_list = even_odd_linkedlist().oddEvenList(head)

        actual = even_odd_linkedlist().to_list(new_list)

        expected = [1, 3, 5, 2, 4]

        assert actual == expected