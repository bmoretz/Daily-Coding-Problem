
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

'''6.1
A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

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


''' 6.5

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

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

''' 6.2
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


''' 6.3

Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of +, -, * or /.

Given the root to such a tree, write a function to evalutate it.

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

''' 6.4

Get tree level with minimum sum

Given a binary tree, return the level of the tree that has the minimum sum. The level of a node is defined as the number of connections requred to get to the root, with the root having level zero.

For example,

        1
    2       3
        4       5

In this tree, level 0 has sum 1, level 1 has sum 5, and level 2 has sum 9, so the level with the minimuim sum is zero.
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