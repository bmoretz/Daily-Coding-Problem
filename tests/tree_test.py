import unittest

from problems.tree import Node
from problems.tree import populate_pre_order
from problems.tree import get_height, get_width
from problems.tree import serialize, deserialize
from problems.tree import count_unival_subtrees1
from problems.tree import reconstruct1, reconstruct2

tree1 = [0,
        [1, [], []],
        [0,
            [1, [1], [1]], 
            [0, [], []]
        ]]

tree2 = ['a',
        ['a', [], []],
        ['a',
            ['a', [], []], 
            ['a', [], ['b']]
        ]]

class Test_InitTree(unittest.TestCase):
    
    def setUp(self):
        self.tree1 = populate_pre_order(tree1)
        self.tree2 = populate_pre_order(tree2)

    def test_case1(self):
        
        assert get_height(self.tree1) == 4

    def test_case2(self):
        assert get_height(self.tree2) == 4

    def test_case3(self):
        assert get_width(self.tree1) == 2

    def test_case4(self):
        assert get_width(self.tree2) == 2

class Test_CountUnivalSubtree1(unittest.TestCase):
    
    def setUp(self):
        self.tree1 = populate_pre_order(tree1)
        self.tree2 = populate_pre_order(tree2)

    def test_case1(self):
        
        subtrees = count_unival_subtrees1(self.tree1)

        assert subtrees == 5

    def test_case2(self):
        subtrees = count_unival_subtrees1(self.tree2)

        assert subtrees == 3

class Test_Serialization(unittest.TestCase):

    def setUp(self):
        self.tree1 = populate_pre_order(tree1)
        self.tree2 = populate_pre_order(tree2)

    def test_case1(self):
        
        ser = serialize(self.tree1)

        tree1 = deserialize(ser)
        
        assert tree1.data == 0
        assert tree1.left.data == 1
        assert tree1.right.data == 0

class Test_Reconstruct1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        
        preorder = ['a', 'b', 'd', 'e', 'c', 'f', 'g']
        inorder = ['d', 'b', 'e', 'a', 'f', 'c', 'g']

        tree = reconstruct1(preorder, inorder)

        assert tree.data == 'a'

        left = tree.left

        assert left.data == 'b'

        assert left.left.data == 'd'
        assert left.right.data == 'e'

        right = tree.right

        assert right.data == 'c'

        assert right.left.data == 'f'
        assert right.right.data == 'g'


class Test_Reconstruct2(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        
        preorder = ['a', 'b', 'd', 'e', 'c', 'f', 'g']
        inorder = ['d', 'b', 'e', 'a', 'f', 'c', 'g']

        tree = reconstruct2(preorder, inorder)

        assert tree.data == 'a'

        left = tree.left

        assert left.data == 'b'

        assert left.left.data == 'd'
        assert left.right.data == 'e'

        right = tree.right

        assert right.data == 'c'

        assert right.left.data == 'f'
        assert right.right.data == 'g'