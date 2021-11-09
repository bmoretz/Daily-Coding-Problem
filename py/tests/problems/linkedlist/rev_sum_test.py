import unittest

from dcp.problems.linkedlist.single import build_list
from dcp.problems.linkedlist.rev_sum import rev_sum1

class Test_ReverseSum1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert rev_sum1(None, None) == None

    def test_case2(self):
        
        n1, n2 = build_list([7, 1, 6]), build_list([5, 9, 3])

        actual = rev_sum1(n1, n2)

        expected = build_list([1, 0, 1, 2])
        
        assert actual == expected
        
    def test_case3(self):
        
        n1, n2 = build_list([7, 1, 6]), build_list([5, 9, 2])

        actual = rev_sum1(n1, n2)

        expected = build_list([9, 1 , 2])
        
        assert actual == expected

    def test_case4(self):
        
        n1, n2 = build_list([1]), build_list([1])

        actual = rev_sum1(n1, n2)

        expected = build_list([2])
        
        assert actual == expected

    def test_case5(self):
        
        n1, n2 = build_list([0, 0, 0, 0]), build_list([9, 9, 9, 9])

        actual = rev_sum1(n1, n2)

        expected = build_list([9, 9, 9, 9])
        
        assert actual == expected

    def test_case6(self):
        
        n1, n2 = build_list([6]), build_list([5, 9, 3])

        actual = rev_sum1(n1, n2)

        expected = build_list([4, 0, 1])
        
        assert actual == expected