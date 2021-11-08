'''Possible BST.

Given an integer n, construct all possible binary search trees with n nodes where all values from [1, ..., n] are used.

For example, given n = 3, return the following trees:

[1, 2, 3]
[1, 3, 2]
[2, 1, 3]
[3, 1, 2]
[3, 2, 1]
'''

from .ds import Node

def make_trees1(N):

    def make_trees(low, high):
        trees = []

        if low > high:
            trees.append(None)
            return trees

        for i in range(low, high + 1):
            left = make_trees(low, i - 1)
            right = make_trees(i + 1, high)

            for l in left:
                for r in right:
                    node = Node(i, left=l, right=r)
                    trees.append(node)

        return trees

    def preorder(root):
        result = []

        if root:
            result.append(root.data)
            result += preorder(root.left)
            result += preorder(root.right)

        return result

    trees, results = make_trees(1, N), []

    for tree in trees:
        results.append(preorder(tree))

    return results