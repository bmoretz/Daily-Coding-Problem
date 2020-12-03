import unittest

from py.leetcode.linkedlist import intersection

class Test_Intersection(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        headA, headB, intersect = intersection().build_list( [4,1], [5,6,1], [8,4,5] )

        actual = intersection().getIntersectionNode( headA, headB )
        expected = intersect

        assert actual == expected

from py.leetcode.linkedlist import rev_linkedlist

class Test_ReverseLinkedList(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        head = rev_linkedlist().build_list([1,2,3,4,5])

        new_list = rev_linkedlist().reverseList_iter(head)

        actual = rev_linkedlist().to_list(new_list)

        expected = [5, 4, 3, 2, 1]

        assert actual == expected

    def test_case2(self):

        head = rev_linkedlist().build_list([1,2,3,4,5])

        new_list = rev_linkedlist().reverseList_rec(head)

        actual = rev_linkedlist().to_list(new_list)

        expected = [5, 4, 3, 2, 1]

        assert actual == expected

from py.leetcode.linkedlist import even_odd_linkedlist

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

from py.leetcode.linkedlist import is_palindrome

class Test_IsPalindrome(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        head = is_palindrome().build_list([1,2,2,1])

        actual = is_palindrome().isPalindrome(head)

        expected = True

        assert actual == expected

    def test_case2(self):

        head = is_palindrome().build_list([1,2,3,2,1])

        actual = is_palindrome().isPalindrome(head)

        expected = True

        assert actual == expected

    def test_case3(self):

        head = is_palindrome().build_list([1,2,3,4,2,1])

        actual = is_palindrome().isPalindrome(head)

        expected = False

        assert actual == expected

from py.leetcode.linkedlist import DoubleLinkedList

class Test_DoubleLinkedList(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        dl = DoubleLinkedList()

        dl.addAtHead(1)
        dl.addAtTail(3)
        dl.addAtIndex(1, 2)

        assert dl.get(0) == 1
        assert dl.get(1) == 2
        assert dl.get(2) == 3

        dl.deleteAtIndex(1)

        assert dl.get(0) == 1
        assert dl.get(1) == 3

        dl.deleteAtIndex(0)

        assert dl.get(0) == 3

    def test_case2(self):

        dl = DoubleLinkedList()

        dl.addAtHead(7)
        dl.addAtTail(7)
        dl.addAtHead(9)
        dl.addAtTail(8)
        dl.addAtHead(6)
        dl.addAtHead(0)

        assert dl.get(0) == 0
        assert dl.get(1) == 6
        assert dl.get(2) == 9
        assert dl.get(3) == 7
        assert dl.get(4) == 7
        assert dl.get(5) == 8

        dl.addAtHead(0)

        assert dl.get(2) == 6
        assert dl.get(5) == 7

        dl.addAtTail(4)

        assert dl.get(7) == 4

from py.leetcode.linkedlist import merge_sorted_lists

class Test_MergeSortedLists(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2 = merge_sorted_lists().build_list([1,2,4]), merge_sorted_lists().build_list([1,3,4])

        merged = merge_sorted_lists().mergeTwoLists(l1, l2)

        actual = merge_sorted_lists().to_vector(merged)

        expected = [1,1,2,3,4,4]

        assert actual == expected

from py.leetcode.linkedlist import add_two_numbers

class Test_AddTwoNumbers(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2 = add_two_numbers().build_list([2,4,3]), add_two_numbers().build_list([5,6,4])

        merged = add_two_numbers().addTwoNumbers(l1, l2)

        actual = add_two_numbers().to_vector(merged)
        expected = [7,0,8]

        assert actual == expected

from py.leetcode.linkedlist import circular_insert

class Test_CircularInsert(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        head = circular_insert().make_list([3,4,1])

        new_list = circular_insert().insert(head, 2)

        actual = circular_insert().to_list(new_list)

        expected = [3,4,1,2]

        assert actual == expected

from py.leetcode.linkedlist import deep_copy_random

class Test_DeepCopyRandom(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        list_str = [[7,None],[13,0],[11,4],[10,2],[1,0]]
        head = deep_copy_random().build_random_list(list_str)

        new_head = deep_copy_random().copyRandomList(head)

        old, new = head, new_head

        while old or new:

            assert old.val == new.val

            if old.random or new.random:
                assert old.random.val == new.random.val

            old, new = old.next, new.next