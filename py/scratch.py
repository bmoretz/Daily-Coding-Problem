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


from problems.tree import Node

def bst_sequence1(tree):

    def weave(first, second, prefix):
        if len(first) == 0 or len(second) == 0:
            

    def all_sequences(node):

        result = []

        if not node:
            return result

        prefix = [node.data]

        left_seq = all_sequences(node.left)
        right_seq = all_sequences(node.right)

        for left in left_seq:
            for right in right_seq:
                weaved = weave()

# tree = Node(2)
# tree.left = Node(1)
# tree.right = Node(3)

tree = Node(4)

tree.left = Node(2)
tree.left.left = Node(1)
tree.left.right = Node(3)

tree.right = Node(6)
tree.right.left = Node(5)
tree.right.right = Node(7)

seq = bst_sequence(tree)

print(seq)