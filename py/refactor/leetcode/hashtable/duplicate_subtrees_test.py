import unittest

from leetcode.hashtable import duplicate_subtrees

class Test_DuplicateSubtrees(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
                
        tree = [1,2,3,4,None,2,4,None,None,4]

        dup = duplicate_subtrees().findDuplicateSubtrees(tree)
        
        assert len(dup) == 2