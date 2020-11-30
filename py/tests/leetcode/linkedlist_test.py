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