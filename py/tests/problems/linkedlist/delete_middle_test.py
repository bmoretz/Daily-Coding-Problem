import unittest

from dcp.problems.linkedlist.single import build_list
from dcp.problems.linkedlist.del_middle import delete_middle1

class Test_DeleteMiddle2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert delete_middle1(None) == None

    def test_case2(self):
        
        actual, target = build_list(['a', 'b', 'c', 'd', 'e', 'f']), 'c'

        node = actual

        while node.data != target:
            node = node.next

        delete_middle1(node)

        expected = build_list(['a', 'b', 'd', 'e', 'f'])
        
        assert actual == expected
        
    def test_case3(self):
        
        actual, target = build_list(['a', 'b', 'c', 'd', 'e', 'f']), 'd'

        node = actual

        while node.data != target:
            node = node.next

        delete_middle1(node)

        expected = build_list(['a', 'b', 'c', 'e', 'f'])
        
        assert actual == expected

    def test_case4(self):
        
        actual, target = build_list(['a', 'b', 'c', 'd', 'e', 'f']), 'd'

        node = actual

        while node.data != target:
            node = node.next

        delete_middle1(node)

        expected = build_list(['a', 'b', 'c', 'e', 'f'])
        
        assert actual == expected

    def test_case5(self):
        
        actual, target = build_list(['a', 'b', 'c', 'd', 'e', 'f']), 'f'

        node = actual

        while node.data != target:
            node = node.next

        delete_middle1(node)

        expected = build_list(['a', 'b', 'c', 'd', 'e', 'f'])
        
        assert actual == expected