
'''Find floor and ceiling.

Given a binary search tree, find the floor and ceiling of a given integer. The floor is the hightest 
element in the tree less than or equal to an integer, while the ceiling is the lowest element in the 
tree greater than or equal to an integer.

If either value does not exist, return None.

'''

def floor_ceiling1(root, k):

    def get_bounds(root, x, floor=None, ceil=None):

        if not root:
            return floor, ceil

        if x == root.data:
            return x, x

        elif x < root.data:
            floor, ceil = get_bounds(root.left, x, floor, root.data)

        elif x > root.data:
            floor, ceil = get_bounds(root.right, x, root.data, ceil)

        return floor, ceil
    
    return get_bounds(root, k, k)


'''Possible BST.

Given an integer n, construct all possible binary search trees with n nodes where all values from [1, ..., n] are used.

For example, given n = 3, return the following trees:

[1, 2, 3]
[1, 3, 2]
[2, 1, 3]
[3, 1, 2]
[3, 2, 1]
'''

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

'''BST Sequences.

A binary search tree was created by traversing through an array from 
left to right and inserting each element. Given a binary search tree
with distinct elements , print all possible arrays that could have lead
to this tree.

EXAMPLE:
        2
      /   \
    1       3

Output: {2, 1, 3}, {2, 3, 1}
'''
