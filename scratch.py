'''Validate BST.

Implement a function to check if a binary tree is a binary search tree.
'''

from problems.tree import Node

def is_bst(node):

    def check_bst(node, flr=None, ceil=None):

        if node == None: return True

        is_valid = False

        if (node.left == None or node.left.data < node.data) and (node.right == None or node.right.data > node.data):
            if (flr == None or flr < node.data) and (ceil == None or ceil > node.data):
                is_valid = True

        if node.left:
            is_valid &= check_bst(node.left, flr, node.data)

        if node.right:
            is_valid &= check_bst(node.right, node.data, ceil)

        return is_valid

    if node is None: return False

    return check_bst(node)

tree = Node(20)

tree.left = Node(10)
tree.left.right = Node(25)

tree.right = Node(30)


v = is_bst(tree)


print(v)