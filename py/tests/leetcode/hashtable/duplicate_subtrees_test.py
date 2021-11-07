import unittest

from dcp.leetcode.hashtable.duplicate_subtrees import findDuplicateSubtrees

class Test_DuplicateSubtrees(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
                
        tree = [1,2,3,4,None,2,4,None,None,4]

        dup = findDuplicateSubtrees(tree)
        
        assert len(dup) == 2