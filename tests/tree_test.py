import unittest

from problems.tree import Node

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

from problems.tree import populate_pre_order
from problems.tree import get_height, get_width
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

from problems.tree import count_unival_subtrees1
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

from problems.tree import count_unival_subtrees2
class Test_CountUnivalSubtree2(unittest.TestCase):
    
    def setUp(self):
        self.tree1 = populate_pre_order(tree1)
        self.tree2 = populate_pre_order(tree2)

    def test_case1(self):
        
        subtrees = count_unival_subtrees2(self.tree1)

        assert subtrees == 5

    def test_case2(self):
        subtrees = count_unival_subtrees2(self.tree2)

        assert subtrees == 5

from problems.tree import serialize, deserialize
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

from problems.tree import reconstruct1
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

from problems.tree import reconstruct2
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

from problems.tree import evaluate1
class Test_Arithmetic1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        ops = ['*',
                ['+', [3], [2]],
                ['+', [4], [5]]]

        operations = populate_pre_order(ops)

        result = evaluate1(operations)

        assert result == 45

    def test_case2(self):

        ops = ['*',
                [2],
                ['+', [4], [5]]]

        operations = populate_pre_order(ops)

        result = evaluate1(operations)

        assert result == 18
        
    def test_case3(self):

        ops = ['*',
                [2],
                [5]]

        operations = populate_pre_order(ops)

        result = evaluate1(operations)

        assert result == 10

from problems.tree import minsum1
class Test_MinSum1(unittest.TestCase):

    def setUp(self):
        self.values1 = [1,
                        [2],
                        [3, [4], [5]]]

        self.values2 = [5,
                        [1],
                        [2, [4], [5]]]


    def test_case1(self):

        tree = populate_pre_order(self.values1)

        min_level = minsum1(tree)

        assert min_level == 0

    def test_case2(self):

        tree = populate_pre_order(self.values2)

        min_level = minsum1(tree)

        assert min_level == 1

from problems.tree import MinTree1
class Test_MinTree1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        tree = MinTree1(None)

        assert tree.root == None

    def test_case2(self):
        tree = MinTree1([1, 2, 3])

        assert tree.height() == 2

        assert tree.root.data == 2
        assert tree.root.left.data == 1
        assert tree.root.right.data == 3

    def test_case3(self):
        tree = MinTree1([1, 2])

        assert tree.height() == 2

        assert tree.root.data == 2
        assert tree.root.left.data == 1

    def test_case4(self):
        tree = MinTree1([1, 2, 3, 4])

        assert tree.height() == 3

        assert tree.root.data == 3

        assert tree.root.left.data == 2
        assert tree.root.left.left.data == 1

        assert tree.root.right.data == 4

    def test_case5(self):
        tree = MinTree1([1, 2, 3, 4, 5, 6, 7])

        assert tree.height() == 3

        assert tree.root.data == 4

        left = tree.root.left

        assert left.data == 2
        assert left.right.data == 3
        assert left.left.data == 1

        right = tree.root.right

        assert right.data == 6
        assert right.left.data == 5
        assert right.right.data == 7

from problems.tree import DepthList
class Test_DepthList(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        
        dl = DepthList(None)

        assert dl
        assert not dl.tree

    '''
    tree 1:

        2
       / \
      1   3
    '''
    def test_case2(self):

        dl = DepthList([1, 2, 3])

        assert dl
        assert dl.tree.height() == 2

        assert dl.tree.root.data == 2
        assert dl.tree.root.left.data == 1
        assert dl.tree.root.right.data == 3

        values = dl.depth_list1()

        assert len(values) == 2

        # Level 1
        assert values[0].data == 2

        # Level 2
        assert values[1].data == 1
        assert values[1].next.data == 3

    '''
    tree 2:
    
        3
       / \
      2   4
     /
    1
    '''
    def test_case3(self):

        dl = DepthList([1, 2, 3, 4])

        assert dl
        assert dl.tree.height() == 3

        assert dl.tree.root.data == 3
        assert dl.tree.root.left.data == 2
        assert dl.tree.root.left.left.data == 1
        assert dl.tree.root.right.data == 4

        values = dl.depth_list1()

        assert len(values) == 3

        # Level 1
        assert values[0].data == 3

        # Level 2
        assert values[1].data == 2
        assert values[1].next.data == 4

        # Level 3
        assert values[2].data == 1

    '''
    tree 3:
    
        3
       /  \
      2    5
     /    /  
    1    4 
    '''
    def test_case4(self):

        dl = DepthList([1, 2, 3, 4, 5])

        assert dl
        assert dl.tree.height() == 3

        assert dl.tree.root.data == 3

        assert dl.tree.root.left.data == 2
        assert dl.tree.root.left.left.data == 1

        assert dl.tree.root.right.data == 5
        assert dl.tree.root.right.left.data == 4

        values = dl.depth_list1()

        assert len(values) == 3

        # Level 1
        assert values[0].data == 3

        # Level 2
        assert values[1].data == 2
        assert values[1].next.data == 5

        # Level 3
        assert values[2].data == 1
        assert values[2].next.data == 4

    '''
    tree 4:
    
         4
       /   \
      2     6
     / \   /  \ 
    1   3 5    7
    '''
    def test_case5(self):

        dl = DepthList([1, 2, 3, 4, 5, 6, 7])

        assert dl
        assert dl.tree.height() == 3

        assert dl.tree.root.data == 4

        left = dl.tree.root.left

        assert left.data == 2
        assert left.left.data == 1
        assert left.right.data == 3

        right = dl.tree.root.right

        assert right.data == 6
        assert right.left.data == 5
        assert right.right.data == 7

        values = dl.depth_list1()

        assert len(values) == 3

        # Level 1
        assert values[0].data == 4

        # Level 2
        assert values[1].data == 2
        assert values[1].next.data == 6

        # Level 3
        assert values[2].data == 1
        assert values[2].next.data == 3
        assert values[2].next.next.data == 5
        assert values[2].next.next.next.data == 7

        '''
        tree 1:

            2
        / \
        1   3
        '''
        def test_case6(self):

            dl = DepthList([1, 2, 3])

            assert dl
            assert dl.tree.height() == 2

            assert dl.tree.root.data == 2
            assert dl.tree.root.left.data == 1
            assert dl.tree.root.right.data == 3

            values = dl.depth_list2()

            assert len(values) == 2

            # Level 1
            assert values[0].data == 2

            # Level 2
            assert values[1].data == 1
            assert values[1].next.data == 3

            '''
            tree 2:
            
                3
            / \
            2   4
            /
            1
            '''
            def test_case7(self):

                dl = DepthList([1, 2, 3, 4])

                assert dl
                assert dl.tree.height() == 3

                assert dl.tree.root.data == 3
                assert dl.tree.root.left.data == 2
                assert dl.tree.root.left.left.data == 1
                assert dl.tree.root.right.data == 4

                values = dl.depth_list2()

                assert len(values) == 3

                # Level 1
                assert values[0].data == 3

                # Level 2
                assert values[1].data == 2
                assert values[1].next.data == 4

                # Level 3
                assert values[2].data == 1

            '''
            tree 3:
            
                3
            /  \
            2    5
            /    /  
            1    4 
            '''
            def test_case7(self):

                dl = DepthList([1, 2, 3, 4, 5])

                assert dl
                assert dl.tree.height() == 3

                assert dl.tree.root.data == 3

                assert dl.tree.root.left.data == 2
                assert dl.tree.root.left.left.data == 1

                assert dl.tree.root.right.data == 5
                assert dl.tree.root.right.left.data == 4

                values = dl.depth_list2()

                assert len(values) == 3

                # Level 1
                assert values[0].data == 3

                # Level 2
                assert values[1].data == 2
                assert values[1].next.data == 5

                # Level 3
                assert values[2].data == 1
                assert values[2].next.data == 4

            '''
            tree 4:
            
                4
            /   \
            2     6
            / \   /  \ 
            1   3 5    7
            '''
            def test_case8(self):

                dl = DepthList([1, 2, 3, 4, 5, 6, 7])

                assert dl
                assert dl.tree.height() == 3

                assert dl.tree.root.data == 4

                left = dl.tree.root.left

                assert left.data == 2
                assert left.left.data == 1
                assert left.right.data == 3

                right = dl.tree.root.right

                assert right.data == 6
                assert right.left.data == 5
                assert right.right.data == 7

                values = dl.depth_list2()

                assert len(values) == 3

                # Level 1
                assert values[0].data == 4

                # Level 2
                assert values[1].data == 2
                assert values[1].next.data == 6

                # Level 3
                assert values[2].data == 1
                assert values[2].next.data == 3
                assert values[2].next.next.data == 5
                assert values[2].next.next.next.data == 7

from problems.tree import is_balanced, TreeNode
class Test_IsBalanced(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        
        root = None

        assert is_balanced(root) == True

    '''
    Tree 1:
                4
              /
            3
          /
        2
      /
    1
    '''
    def test_case2(self):
        root = TreeNode(4)
        root.left = TreeNode(3)
        root.left.left = TreeNode(2)
        root.left.left.left = TreeNode(1)

        assert is_balanced(root) == False

    '''
    Tree 2:
        2
      /   \
    1       3
    '''
    def test_case3(self):

        root = TreeNode(2)

        root.left = TreeNode(1)
        root.right = TreeNode(3)

        assert is_balanced(root) == True

    '''
    Tree 3:
        2
      /   \
    1       3
              \
                4
                   \
                     5
    '''
    def test_case3(self):

        root = TreeNode(2)

        root.left = TreeNode(1)
        
        root.right = TreeNode(3)
        root.right.right = TreeNode(4)
        root.right.right.right = TreeNode(5)

        assert is_balanced(root) == False

    '''
    Tree 4:
           2
         /   \
        1      3
      /          \
    0              4
                    \
                      5
    '''
    def test_case3(self):

        root = TreeNode(2)

        root.left = TreeNode(1)
        root.left.left = TreeNode(0)

        root.right = TreeNode(3)
        root.right.right = TreeNode(4)
        root.right.right.right = TreeNode(5)

        assert is_balanced(root) == True

        