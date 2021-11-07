import unittest

from leetcode.linkedlist import add_two_numbers

class Test_AddTwoNumbers(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2 = add_two_numbers().build_list([2,4,3]), add_two_numbers().build_list([5,6,4])

        merged = add_two_numbers().addTwoNumbers(l1, l2)

        actual = add_two_numbers().to_vector(merged)
        expected = [7,0,8]

        assert actual == expected