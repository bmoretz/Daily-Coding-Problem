import unittest

from py.problems.tree import Node

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

from py.problems.tree import populate_pre_order
from py.problems.tree import get_height, get_width
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

from py.problems.tree import count_unival_subtrees1
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

from py.problems.tree import count_unival_subtrees2
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

from py.problems.tree import serialize, deserialize
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

from py.problems.tree import reconstruct1
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

from py.problems.tree import reconstruct2
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

from py.problems.tree import evaluate1
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

from py.problems.tree import minsum1
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

from py.problems.tree import MinTree1
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

from py.problems.tree import DepthList
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

from py.problems.tree import is_balanced, Node
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
        root = Node(4)
        root.left = Node(3)
        root.left.left = Node(2)
        root.left.left.left = Node(1)

        assert is_balanced(root) == False

    '''
    Tree 2:
        2
      /   \
    1       3
    '''
    def test_case3(self):

        root = Node(2)

        root.left = Node(1)
        root.right = Node(3)

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

        root = Node(2)

        root.left = Node(1)
        
        root.right = Node(3)
        root.right.right = Node(4)
        root.right.right.right = Node(5)

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

        root = Node(2)

        root.left = Node(1)
        root.left.left = Node(0)

        root.right = Node(3)
        root.right.right = Node(4)
        root.right.right.right = Node(5)

        assert is_balanced(root) == True

from py.problems.tree import is_bst
class Test_IsBST(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        tree = None

        assert is_bst(tree) == False
    
    '''
    Tree #1:

            3
          /   \
        2       4
      /
     1 
    '''
    def test_case2(self):

        tree = Node(3)

        tree.left = Node(2)
        tree.left.left = Node(1)

        tree.right = Node(4)
        
        assert is_bst(tree) == True

    '''
    Tree #2 (ties):

            3
          /   \
        2       4
      /           \
     1              4
    '''
    def test_case2(self):

        tree = Node(3)

        tree.left = Node(2)
        tree.left.left = Node(1)

        tree.right = Node(4)
        tree.right.right = Node(4)

        assert is_bst(tree) == False

    '''
    Tree #3:

            1
          /   \
        2       3
      /           \
     4              4
    '''
    def test_case3(self):

        tree = Node(1)

        tree.left = Node(2)
        tree.left.left = Node(4)

        tree.right = Node(3)
        tree.right.right = Node(4)
        
        assert is_bst(tree) == False

    '''
    Tree #3:

            4
          /   \
        2       6
      /  \     /  \
     1     3  5     5
    '''
    def test_case4(self):

        tree = Node(4)

        tree.left = Node(2)
        tree.left.left = Node(1)
        tree.left.right = Node(3)

        tree.right = Node(6)
        tree.right.left = Node(5)
        tree.right.right = Node(5)

        assert is_bst(tree) == False

    '''
    Tree #4:

            4
          /   \
        2       6
      /  \     /  \
     1     3  5     7
    '''
    def test_case5(self):

        tree = Node(4)

        tree.left = Node(2)
        tree.left.left = Node(1)
        tree.left.right = Node(3)

        tree.right = Node(6)
        tree.right.left = Node(5)
        tree.right.right = Node(7)

        assert is_bst(tree) == True

    '''
    Tree #5:

           20
          /   \
        10     30
         \    
          25  
    '''
    def test_case6(self):

        tree = Node(20)

        tree.left = Node(10)
        tree.left.right = Node(25)

        tree.right = Node(30)

        assert is_bst(tree) == False

    '''
    Tree #6:

           20
          /  \
        10    30
       /  \    
      5    15
     /  \    \
    3    7    17
    '''
    def test_case7(self):

        tree = Node(20)

        tree.left = Node(10)
        tree.left.left = Node(5)
        tree.left.left.left = Node(3)
        tree.left.left.right = Node(7)

        tree.left.right = Node(15)
        tree.left.right.right = Node(17)

        tree.right = Node(30)

        assert is_bst(tree) == True

    '''
    Tree #7:

            4
          /   \
        2       5
      /  \     /  \
     1     3  6     7
    '''
    def test_case5(self):

        tree = Node(4)

        tree.left = Node(2)
        tree.left.left = Node(1)
        tree.left.right = Node(3)

        tree.right = Node(5)
        tree.right.left = Node(6)
        tree.right.right = Node(7)

        assert is_bst(tree) == False

from py.problems.tree import successor
class Test_Successor(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        assert successor(None, 21) == None

    def test_case2(self):

        tree = Node(20)

        assert successor(tree, 10) == None

    '''
    successor(33) == None

            3
         /    \
        2      20
            /     \
          10        30
        /          /  \
       5          25    33
                /  \
              23    28
            /
           21
    '''
    def test_case3(self):

        tree = Node(3)

        tree.left = Node(2)
        tree.right = Node(20)

        tree.right.left = Node(10)
        tree.right.left.left = Node(5)

        tree.right.right = Node(30)
        tree.right.right.left = Node(25)

        tree.right.right.left.left = Node(23)

        tree.right.right.left.left.left = Node(21)

        tree.right.right.left.right = Node(28)

        tree.right.right.right = Node(33)

        # case where we want the successor to the max value node
        # which should be None
        assert successor(tree, 33) == None

    '''
    successor(20) == 21

            3
         /    \
        2      20
            /     \
          10        30
        /          /  \
       5          25    33
                /  \
              23    28
            /
           21
    '''
    def test_case4(self):

        tree = Node(3)

        tree.left = Node(2)
        tree.right = Node(20)

        tree.right.left = Node(10)
        tree.right.left.left = Node(5)

        tree.right.right = Node(30)
        tree.right.right.left = Node(25)

        tree.right.right.left.left = Node(23)

        tree.right.right.left.left.left = Node(21)

        tree.right.right.left.right = Node(28)

        tree.right.right.right = Node(33)

        # case where we want the successor to be in the
        # right tree.
        actual = successor(tree, 20)

        assert actual.data == 21

    '''
    successor(3) == 5

            3
         /    \
        2      20
            /     \
          10        30
        /          /  \
       5          25    33
                /  \
              23    28
            /
           21
    '''
    def test_case5(self):

        tree = Node(3)

        tree.left = Node(2)
        tree.right = Node(20)

        tree.right.left = Node(10)
        tree.right.left.left = Node(5)

        tree.right.right = Node(30)
        tree.right.right.left = Node(25)

        tree.right.right.left.left = Node(23)

        tree.right.right.left.left.left = Node(21)

        tree.right.right.left.right = Node(28)

        tree.right.right.right = Node(33)

        # case where we want the successor to be in the
        # right tree.

        actual = successor(tree, 3)

        assert actual.data == 5

    '''
    successor(28) == 30

            3
         /    \
        2      20
            /     \
          10        30
        /          /  \
       5          25    33
                /  \
              23    28
            /
           21
    '''
    def test_case6(self):

        tree = Node(3)

        tree.left = Node(2)
        tree.right = Node(20)

        tree.right.left = Node(10)
        tree.right.left.left = Node(5)

        tree.right.right = Node(30)
        tree.right.right.left = Node(25)

        tree.right.right.left.left = Node(23)

        tree.right.right.left.left.left = Node(21)

        tree.right.right.left.right = Node(28)

        tree.right.right.right = Node(33)

        # case where we want the successor to be in the
        # previously traversed path.
        actual = successor(tree, 28)
        
        assert actual.data == 30

from py.problems.tree import first_common_ancestor1
class Test_FirstCommonAncestor1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        assert first_common_ancestor1(None, Node(3), Node(5)) == None
        assert first_common_ancestor1(None, None, None) == None
        assert first_common_ancestor1(None, Node(3), None) == None
        assert first_common_ancestor1(None, None, Node(4)) == None

    '''
    Tree #1:

          5
        /    \
       3       8
    /   \      /  \
   12    10  2     7
            / \
           6   18
    '''    
    def test_case2(self):

        tree = Node(5)

        tree.left = Node(3)
        tree.left.left = Node(12)
        tree.left.right = Node(10)

        tree.right = Node(8)
        tree.right.left = Node(2)
        tree.right.left.left = Node(6)
        tree.right.left.right = Node(18)

        tree.right.right = Node(7)

        actual, expected = first_common_ancestor1(tree, 2, 7), 8

        assert actual == expected

    def test_case3(self):

        tree = Node(5)

        tree.left = Node(3)
        tree.left.left = Node(12)
        tree.left.right = Node(10)

        tree.right = Node(8)
        tree.right.left = Node(2)
        tree.right.left.left = Node(6)
        tree.right.left.right = Node(18)

        tree.right.right = Node(7)

        actual, expected = first_common_ancestor1(tree, 6, 7), 8

        assert actual == expected

    def test_case4(self):

        tree = Node(5)

        tree.left = Node(3)
        tree.left.left = Node(12)
        tree.left.right = Node(10)

        tree.right = Node(8)
        tree.right.left = Node(2)
        tree.right.left.left = Node(6)
        tree.right.left.right = Node(18)

        tree.right.right = Node(7)

        actual, expected = first_common_ancestor1(tree, 10, 18), 5

        assert actual == expected

    def test_case5(self):

        tree = Node(5)

        tree.left = Node(3)
        tree.left.left = Node(12)
        tree.left.right = Node(10)

        tree.right = Node(8)
        tree.right.left = Node(2)
        tree.right.left.left = Node(6)
        tree.right.left.right = Node(18)

        tree.right.right = Node(7)

        actual, expected = first_common_ancestor1(tree, 10, 38), None

        assert actual == expected

from py.problems.tree import check_subtree1
class Test_CheckSubtree1(unittest.TestCase):

    def setUp(self):
        pass

    '''
    Tree set #1

               50
            /      \
          30         70
        /     \   /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            60
           /   \
         55     65 
    '''
    def test_case1(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(80)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(60)
        t2.left = Node(55)
        t2.right = Node(65)

        actual = check_subtree1(t1, t2)
        expected = True

        assert actual == expected

    '''
    Tree set #1

               50
            /      \
          30         70
        /     \   /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            60
           /
         55      
    '''
    def test_case2(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(80)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(60)
        t2.left = Node(55)
        
        actual = check_subtree1(t1, t2)
        expected = False

        assert actual == expected

    '''
    Tree set #1

               50
            /      \
          30         70
        /    \    /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            20
           /
          25 
    '''
    def test_case3(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(20)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(20)
        t2.left = Node(25)
        
        actual = check_subtree1(t1, t2)
        expected = False

        assert actual == expected

    '''
    Tree set #1

               50
            /      \
          30         70
        /    \    /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            20
              \
               25
    '''
    def test_case4(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(20)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(20)
        t2.right = Node(25)
        
        actual = check_subtree1(t1, t2)
        expected = True

        assert actual == expected

    '''
    Tree set #1

               50
            /      \
          30         70
        /    \    /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            60
    '''
    def test_case5(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(20)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(60)
        
        actual = check_subtree1(t1, t2)
        expected = False

        assert actual == expected

    '''
    Tree set #1

               50
            /      \
          30         70
        /    \    /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            65
    '''
    def test_case6(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(20)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(65)
        
        actual = check_subtree1(t1, t2)
        expected = True

        assert actual == expected

from py.problems.tree import check_subtree2
class Test_CheckSubtree2(unittest.TestCase):

    def setUp(self):
        pass

    '''
    Tree set #1

               50
            /      \
          30         70
        /     \   /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            60
           /   \
         55     65 
    '''
    def test_case1(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(80)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(60)
        t2.left = Node(55)
        t2.right = Node(65)

        actual = check_subtree2(t1, t2)
        expected = True

        assert actual == expected

    '''
    Tree set #1

               50
            /      \
          30         70
        /     \   /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            60
           /
         55
    '''
    def test_case2(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(80)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(60)
        t2.left = Node(55)
        
        actual = check_subtree2(t1, t2)
        expected = False

        assert actual == expected

    '''
    Tree set #1

               50
            /      \
          30         70
        /    \    /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            20
           /
          25 
    '''
    def test_case3(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(20)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(20)
        t2.left = Node(25)
        
        actual = check_subtree2(t1, t2)
        expected = False

        assert actual == expected

    '''
    Tree set #1

               50
            /      \
          30         70
        /    \    /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            20
              \
               25
    '''
    def test_case4(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(20)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(20)
        t2.right = Node(25)
        
        actual = check_subtree2(t1, t2)
        expected = True

        assert actual == expected

    '''
    Tree set #1

               50
            /      \
          30         70
        /    \    /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            60
    '''
    def test_case5(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(20)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(60)
        
        actual = check_subtree2(t1, t2)
        expected = True

        assert actual == expected

    '''
    Tree set #1

               50
            /      \
          30         70
        /    \    /     \ 
      20      40 60      80
        \       /  \    /   \
        25     55   65 75    90
    

            65
    '''
    def test_case6(self):
        t1 = Node(50)

        t1.left = Node(30)
        t1.left.left = Node(20)
        t1.left.left.right = Node(25)
        t1.left.right = Node(40)

        t1.right = Node(70)
        t1.right.left = Node(60)
        t1.right.left.left = Node(55)
        t1.right.left.right = Node(65)

        t1.right.right = Node(20)
        t1.right.right.left = Node(75)
        t1.right.right.right = Node(90)

        t2 = Node(65)
        
        actual = check_subtree2(t1, t2)
        expected = True

        assert actual == expected

from py.problems.tree import RandomBinaryTree1
class Test_RandomBinaryTree1(unittest.TestCase):

    def setUp(self):
        pass

    '''
    Tree #1:

            40
          /     \
        30       60
      /    \   /    \
     10    20 50     70
    '''
    def test_case1(self):
        
        tree = RandomBinaryTree1()

        node_values = [40, 30, 60, 10, 20, 50, 70]

        for val in node_values:
            tree.insert(val)

        val1 = tree.find(10)
        assert val1 != None

        val2 = tree.find(88)
        assert val2 == None

        val3 = tree.find(50)
        assert val3 != None

        tree.delete(30)
        assert tree.find(30) == None

        tree.delete(40)
        assert tree.find(40) == None

    def test_case2(self):
        
        tree = RandomBinaryTree1()

        node_values = [40, 30, 60, 10, 20, 50, 70]

        for val in node_values:
            tree.insert(val)

        for _ in range(0, 5):

            actual = tree.get_random_node()

            assert actual in node_values

    '''
    Tree #2:

            40
          /     \
        30       60
      /    \   /    \
     10    20 50     70
     /        /         \
   14      40             81
    '''
    def test_case3(self):
        
        tree = RandomBinaryTree1()

        node_values = [40, 30, 60, 10, 20, 50, 70, 40, 14, 81]

        for val in node_values:
            tree.insert(val)

        for _ in range(0, 5):

            actual = tree.get_random_node()

            assert actual in node_values

        tree.delete(40) # dup 40

        assert tree.find(40) != None

        tree.delete(40)

        assert tree.find(40) == None

        for _ in range(0, 5):

            assert tree.get_random_node() != 40

    '''
    Tree #2:

            40
          /     \
        30       60
      /    \   /    \
     10    20 50     70
     /        /         \
   14      40             81
    '''
    def test_case4(self):
        
        tree = RandomBinaryTree1()

        node_values = [40, 30, 60, 10, 20, 50, 70, 40, 14, 81]

        for val in node_values:
            tree.insert(val)

        for val in node_values:
            tree.delete(val)

        assert tree.root == None