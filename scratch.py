from problems.tree import Node
from problems.tree import populate_pre_order
from problems.tree import get_height, get_width

''' 6.4

Get tree level with minimum sum

Given a binary tree, return the level of the tree that has the minimum sum. The level of a node is defined as the number of connections requred to get to the root, with the root having level zero.

For example,

        1
    2       3
        4       5

In this tree, level 0 has sum 1, level 1 has sum 5, and level 2 has sum 9, so the level with the minimuim sum is zero.
'''


values1 = [1,
            [2],
            [3, [4], [5]]]

values2 = [5,
            [1],
            [2, [4], [5]]]

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

tree = populate_pre_order(values2)

val = minsum1(tree)

print(val)
