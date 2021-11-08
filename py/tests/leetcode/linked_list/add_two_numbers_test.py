import unittest

from dcp.leetcode.linkedlist.add_two_numbers import addTwoNumbers, build_list, to_vector

class Test_AddTwoNumbers(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        l1, l2 = build_list([2,4,3]), build_list([5,6,4])

        merged = addTwoNumbers(l1, l2)

        actual = to_vector(merged)
        expected = [7,0,8]

        assert actual == expected