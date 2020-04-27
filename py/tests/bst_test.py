import unittest

from py.problems.bst import Node, BST

from py.problems.bst import floor_ceiling1
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

from py.problems.bst import built_bst1
class Test_BuildBST1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        values = [1, 2, 3, 4, 5, 6, 7]

        tree = built_bst1(values)

        assert tree.data == 4

        left = tree.left
        assert left.data == 2
        assert left.left.data == 1
        assert left.right.data == 3

        right = tree.right
        assert right.data == 6
        assert right.left.data == 5
        assert right.right.data == 7

    def test_case2(self):
        
        values = [1, 2, 3, 4]

        root = built_bst1(values)

        assert root.data == 3

        left = root.left

        assert left.data == 2
        assert left.left.data == 1

        assert root.right.data == 4

from py.problems.bst import make_trees1
class Test_MakeTrees1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case3(self):       
        
        trees = make_trees1(N = 3)

        assert trees[0] == [1, 2, 3]
        assert trees[1] == [1, 3, 2]
        assert trees[2] == [2, 1, 3]
        assert trees[3] == [3, 1, 2]
        assert trees[4] == [3, 2, 1]