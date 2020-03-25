
class Node:

    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        return f'<{self.data}, {self.left}, {self.right}>'

'''Return a (pre-ordered) tree from a given recursive list.'''
def populate_pre_order(data):
    
    if not data: return None

    node = Node(data[0])

    if len(data) > 1:
        node.left = populate_pre_order(data[1])
    
    if len(data) > 2:
        node.right = populate_pre_order(data[2])
        
    return node

'''Return the max height of a given tree.'''
def get_height(root):

    if not root: return 0

    left = get_height(root.left)
    right = get_height(root.right)

    return (left + 1) if (left > right) else (right + 1)

def get_width_rec(root, count, level):

    if root is not None:
        count[level] += 1
        get_width_rec(root.left, count, level + 1)
        get_width_rec(root.right, count, level + 1)

'''Return the max width of the tree.'''
def get_width(root):

    height = get_height(root)

    count, level = [0] * height, 0

    get_width_rec(root, count, level)

    _max = count[0]
    for index in range(len(count)):
        _max = max(_max, count[index])

    return _max

'''Count Unival Value.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the tree:

        0
    1       0
        1       0
    1       1

Should return 5.
'''

def is_unival(root):
    return unival_helper(root, root.data)

def unival_helper(root, value):

    if root is None:
        return True

    if root.data == value:
        return unival_helper(root.left, value) and \
            unival_helper(root.right, value)

    return False

'''O(n^2) count universal value subtrees'''
def count_unival_subtrees1(root):
    if root is None:
        return 0

    left = count_unival_subtrees1(root.left)
    right = count_unival_subtrees1(root.right)

    return (1 + left + right) if is_unival(root) else left + right

'''O(n^2) count universal value subtrees #2'''
def count_unival_subtrees2(tree):

    def is_univariate(node):

        if node.left == None and node.right == None: return True

        if node.left != None and node.right != None and \
            node.left.data == node.right.data == node.data:
            return True

        return False
    
    def count_univariate(root):

        if root == None: return 0

        value = 1 if is_univariate(root) else 0

        if root.left != None:
            value += count_univariate(root.left)

        if root.right != None:
            value += count_univariate(root.right)

        return value

    return count_univariate(tree)

'''Serialize Tree.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which will deserialize the string back into the tree.

'''

def serialize(node):

    if not node: return '#'

    return '{} {} {}'.format(node.data, serialize(node.left), serialize(node.right))

def deserialize(data):

    def helper():
        val = next(vals)
        
        if val == '#':
            return None
        
        node = Node(int(val))
        node.left = helper()
        node.right = helper()

        return node

    vals = iter(data.split())

    return helper()

''' Construct Tree.

Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

For example, given the following pre-order traversal:

[a, b, d, e, c, f, g]

And the following in-order traversal:

[d, b, e, a, f, c, g]

You should return the following tree:

        a
    b       c
d      e  f    g
'''

def reconstruct1(preorder, inorder):

    def reconstruct(preorder, inorder):
        if not preorder or not inorder: return None

        mid = round( ( len(inorder) ) / 2)

        node = Node(preorder[0])

        left = preorder[1:mid]

        if left and mid != 0:
            node.left = reconstruct(left, left)

        right = preorder[mid:]

        if right and mid != 0: 
            node.right = reconstruct(right, right)

        return node

    return reconstruct(preorder, inorder)
    
def reconstruct2(preorder, inorder):

    def reconstruct(preorder, inorder):
        if not preorder and not inorder:
            return None

        root = Node(preorder[0])

        if len(preorder) == len(inorder) == 1:
            return root
 
        root_i = inorder.index(root.data) if len(inorder) > 1 else 0
        root.left = reconstruct(preorder[1:1 + root_i],
                                inorder[0:root_i])
        root.right = reconstruct(preorder[1 + root_i:],
                                        inorder[root_i + 1:])

        return root

    return reconstruct(preorder, inorder)


''' Evaluate Arithmetic.

Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of +, -, * or /.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

        *
    +       -
3      2 4    5

Should return 45, as it is (3 + 2) * (4 + 5).
'''

def evaluate1(root):

    operations = { 
        '+' : lambda x,y: x + y,
        '-' : lambda x,y: x - y,
        '*' : lambda x,y: x * y,
        '\\' : lambda x,y: x / y
    }

    def op(op, l, r):
        return operations[op](l, r) if op in operations.keys() else None

    def eval_node(node):
         return node.data if isinstance( node.data, int ) else evaluate(node)

    def evaluate(root):
        if not root: return None

        operation = root.data
        
        left = eval_node(root.left)

        right = eval_node(root.right)
        
        return op(operation, left, right)

    return evaluate(root)

'''Minimum Sum Tree.

Get tree level with minimum sum

Given a binary tree, return the level of the tree that has the minimum sum. The level of a node is defined as the number of connections required to get to the root, with the root having level zero.

For example,

        1
    2       3
        4       5

In this tree, level 0 has sum 1, level 1 has sum 5, and level 2 has sum 9, so the level with the minimum sum is zero.
'''

def minsum1(root):

    values = {}

    def evaluate(root, level = 1):
        if not root: return None
        
        if root.left or root.right: values[level] = 0

        if root.left:
            values[level] += root.left.data
            evaluate(root.left, level + 1)

        if root.right:
            values[level] += root.right.data
            evaluate(root.right, level + 1)

    if root: 
        values[0] = root.data
        evaluate(root)
    
    return min(values, key = values.get )


'''Minimal Tree.

Given a sorted (increasing order) array with unique integer elements, write
an algorithm to create a binary search tree with minimal height.
'''

class MinTree1():

    class Node():

        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None
        
        def is_full(self):
            return self.left != None and self.right != None

        def is_leaf(self):
            return self.left == None and self.right == None

    def __init__(self, values):
        self.root = None

        if values != None and len(values) > 0:
            self.root = self.__create_tree(values)

    def __create_tree(self, values):
        
        n = len(values)

        if n == 0: return None

        mid = n // 2

        root = self.Node(values[mid])

        if n > 1:
            root.left = self.__create_tree(values[:mid])
            root.right = self.__create_tree(values[mid + 1:])

        return root

    def height(self):

        def height(self, parent, level=0):
            
            if parent == None: 
                return level

            level = max(height(self, parent.left, level + 1), height(self, parent.right, level + 1))

            return level

        return height(self, self.root)

'''List of Depths.

Given a binary tree, design an algorithm which creates a linked list of all the nodes
at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
'''

class DepthList():

    class Node():
        def __init__(self, data):
            self.data = data
            self.next = None

    class BinaryTree():

        class Node():
            def __init__(self, data):
                self.data = data
                self.left = None
                self.right = None
                
        def __init__(self, values):
            self.root = None

            if len(values) > 0:
                self.root = self.__create_tree(values)

        def __create_tree(self, values):
            
            n = len(values)

            if n == 0: return None

            mid = n // 2

            root = self.Node(values[mid])

            if n > 1:
                root.left = self.__create_tree(values[:mid])
                root.right = self.__create_tree(values[mid + 1:])

            return root

        def height(self, node=None, level=0):
            
            if level == 0:
                node = self.root

            if node == None:
                return level

            level = max(self.height(node.left, level + 1), self.height(node.right, level + 1))

            return level

    def __init__(self, values):

        self.tree = None

        if values: self.tree = self.BinaryTree(values)

    ''' Solution #1
    
    This solution is iterative in nature. We process the current node
    building a linked list of values from the data in the tree nodes,
    and at the same time putting the children of that levels nodes
    into a seprate list to be processed during the next iteration.

    run-time: O(N), space: O(N) 
    '''

    def depth_list1(self):
        
        levels, nodes = [], [self.tree.root]

        while nodes:

            lvl = self.process_level(nodes)

            levels.append(lvl[0])
            nodes = lvl[1]

        return levels

    def process_level(self, nodes):
        
        children = []
        head, prev = None, None

        for node in nodes:
            
            ln = self.Node(node.data)

            if head == None:
                head, prev = ln, ln
            else:
                prev.next = ln

            if node.left: children.append(node.left)
            if node.right: children.append(node.right)

            prev = ln
        
        return (head, children)

    ''' Solution #2

    This solution is recursive in nature, processing each node independently.

    When we process a node, we check to see if the level has a linked list head
    element, if not we add it. Then, as we process the elements down the tree,
    we get the list associated with that level and traverse to the end, appending
    that node to the tail of the list.

    run-time O(n), space: O(n log n) 
    '''
    def depth_list2(self):

        return self.build_level(self.tree.root)  

    def build_level(self, node, level=0, levels=[]):
    
        lst_node = self.Node(node.data)

        if len(levels) == level:
            levels.append(lst_node)
        else:
            
            current, prev = levels[level], None

            while current != None:
                prev = current
                current = current.next

            prev.next = lst_node

        if node.left: self.build_level(node.left, level + 1, levels)
        if node.right: self.build_level(node.right, level + 1, levels)

        return levels

'''Check Balanced.

Implement a function to check if a binary tree is balanced.

For the purposes of this question, a balanced tree is defined to be a tree such
that the heights of the two subtrees of any node never differ by more than one.
'''

def is_balanced(tree):

    def leaf_count(node, count=0):

        if node == None: return count

        level_count = 0

        if node.left:
            level_count += leaf_count(node.left, count)
            level_count += 1
        
        if node.right:
            level_count -= leaf_count(node.right, count)
            level_count -= 1

        return level_count

    count = leaf_count(tree)

    return abs(leaf_count(tree)) <= 1

'''Validate BST.

Implement a function to check if a binary tree is a binary search tree.
'''

def is_bst(node):

    if node is None: return False

    is_valid = True

    if node.left:
        is_valid &= is_bst(node.left)
        is_valid &= node.left.data < node.data

    if not is_valid: return is_valid
    
    if node.right:
        is_valid &= is_bst(node.right)
        is_valid &= node.right.data >= node.data

    return is_valid