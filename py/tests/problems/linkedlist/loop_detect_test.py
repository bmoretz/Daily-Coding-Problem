import unittest

from dcp.problems.linkedlist.node import build_ref_list
from dcp.problems.linkedlist.loop_detect import detect_loop1

class Test_DetectLoop1(unittest.TestCase):

    @staticmethod
    def set_loop(node, loop_back):

        loop_node, prev = None, None

        while node != None:
            if node.data == loop_back:
                loop_node = node
            prev = node
            node = node.next

        prev.next = loop_node

    def setUp(self):
        pass

    def test_case1(self):

        assert detect_loop1(None) == None

    def test_case2(self):
        
        node = build_ref_list(['A', 'B', 'C', 'D', 'E'])

        self.set_loop(node, 'C')

        actual = detect_loop1(node).data

        expected = 'C'

        assert actual == expected
        
    def test_case3(self):

        node = build_ref_list(['A', 'B', 'C', 'D', 'E'])

        self.set_loop(node, 'A')

        actual = detect_loop1(node).data

        expected = 'A'

        assert actual == expected

    def test_case4(self):
        
        node = build_ref_list(['A', 'B', 'C', 'D', 'E'])

        self.set_loop(node, 'D')

        actual = detect_loop1(node).data

        expected = 'D'

        assert actual == expected