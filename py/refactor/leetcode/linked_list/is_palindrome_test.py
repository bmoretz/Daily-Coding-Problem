import unittest

from leetcode.linkedlist import is_palindrome

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