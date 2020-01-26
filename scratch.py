from collections import defaultdict

from problems.tree import Node
from problems.tree import populate_pre_order
from problems.tree import get_height, get_width

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

def count_unival_subtrees(root):
    if root is None:
        return 0

    left = count_unival_subtrees(root.left)
    right = count_unival_subtrees(root.right)

    return (1 + left + right) if is_unival(root) else left + right

data = ['a',
        ['a', [], []],
        ['a',
            ['a', [], []], 
            ['a', [], ['b']]
        ]]

tree = populate_pre_order(data)

print(get_width(tree))
