'''Validate BST.

Implement a function to check if a binary tree is a binary search tree.
'''

from problems.tree import Node

root = Node(3)

root.left = Node(2)
root.left.left = Node(1)

root.right = Node(4)
root.right.right = Node(4)

def is_bst(node):

    if node is None: return False

    is_valid = True

    if node.left:
        is_valid &= is_bst(node.left)
        is_valid &= node.left.data < node.data

    if not is_valid: return is_bst
    
    if node.right:
        is_valid &= is_bst(node.right)
        is_valid &= node.right.data >= node.data

    return is_valid

v = is_bst(root)

print(v)