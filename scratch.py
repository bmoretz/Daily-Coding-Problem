from problems.tree import Node
from problems.tree import populate_pre_order
from problems.tree import get_height, get_width

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


preorder = ['a', 'b', 'd', 'e', 'c', 'f', 'g']
inorder = ['d', 'b', 'e', 'a', 'f', 'c', 'g']


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


tree = reconstruct(preorder, inorder)

print(tree)
