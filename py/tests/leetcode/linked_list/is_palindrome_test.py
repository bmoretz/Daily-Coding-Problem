import unittest

from dcp.leetcode.linkedlist.is_palindrome import isPalindrome, build_list

class Test_IsPalindrome(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        head = build_list([1,2,2,1])

        actual = isPalindrome(head)

        expected = True

        assert actual == expected

    def test_case2(self):

        head = build_list([1,2,3,2,1])

        actual = isPalindrome(head)

        expected = True

        assert actual == expected

    def test_case3(self):

        head = build_list([1,2,3,4,2,1])

        actual = isPalindrome(head)

        expected = False

        assert actual == expected