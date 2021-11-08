import unittest

from dcp.problems.linkedlist.single import build_list
from dcp.problems.linkedlist.partition import partition1

class Test_Partition1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert partition1(None, 0) == None

    def test_case2(self):
        
        head, partition = build_list([3, 5, 8, 5, 10, 2, 1]), 3

        actual = partition1(head, partition)

        expected = build_list([2, 1, 3, 5, 8, 5, 10])
        
        assert actual == expected
        
    def test_case3(self):
        
        head, partition = build_list([3, 5, 8, 5, 10, 2, 1]), 5

        actual = partition1(head, partition)

        expected = build_list([3, 2, 1, 5, 8, 5, 10])
        
        assert actual == expected

    def test_case4(self):
        
        head, partition = build_list([3, 5, 8, 5, 10, 2, 1]), 10

        actual = partition1(head, partition)

        expected = build_list([3, 5, 8, 5, 2, 1, 10])
        
        assert actual == expected

    def test_case5(self):
        
        head, partition = build_list([3, 5, 8, 5, 10, 2, 1]), 1

        actual = partition1(head, partition)

        expected = build_list([3, 5, 8, 5, 10, 2, 1])
        
        assert actual == expected