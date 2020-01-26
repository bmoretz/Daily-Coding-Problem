
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