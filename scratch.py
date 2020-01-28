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

tree = reconstruct2(preorder, inorder)

print(tree)
