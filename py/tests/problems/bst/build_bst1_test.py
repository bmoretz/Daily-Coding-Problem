import unittest

from problems.bst import built_bst1

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