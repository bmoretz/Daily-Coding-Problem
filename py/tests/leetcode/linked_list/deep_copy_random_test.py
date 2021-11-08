import unittest

from dcp.leetcode.linkedlist.deep_copy_random import copyRandomList, build_random_list

class Test_DeepCopyRandom(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        list_str = [[7,None],[13,0],[11,4],[10,2],[1,0]]
        head = build_random_list(list_str)

        new_head = copyRandomList(head)

        old, new = head, new_head

        while old or new:

            assert old.val == new.val

            if old.random or new.random:
                assert old.random.val == new.random.val

            old, new = old.next, new.next