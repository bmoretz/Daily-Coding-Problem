'''7.2

Given a sorted array, convert it into a hight-balanced binary search tree.

'''

from problems.bst import Node

values = [1, 2, 3, 4]

def built_bst1(values):

    def build_node(values):

        if not values:
            return None

        mid = len(values) // 2

        root = Node(values[mid])
        root.left = build_node(values[:mid])
        root.right = build_node(values[mid + 1:])

        return root

    return build_node(values)

tree = built_bst1(values)

print(tree)
