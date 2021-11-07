import unittest

from dcp.problems.bst.ds import BST
from dcp.problems.bst.floor_ceiling import floor_ceiling1

class Test_FloorCeiling1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        values, tree = [7, 5, 10, -1, 6, 25], BST()

        for v in values:
            tree.insert(v)

        assert floor_ceiling1(tree.root, 8) == (7, 10)

    def test_case2(self):
        
        values, tree = [7, 5, 10, -1, 6, 25], BST()

        for v in values:
            tree.insert(v)

        assert floor_ceiling1(tree.root, 6) == (6, 6)