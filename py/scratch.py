'''First Common Ancestor:

Design an algorithm and write code to find the first common ancestor of two
nodes in a binary tree. Avoid storing additional nodes in a data structure.

NOTE: This is not necessarily a binary search tree.
'''


from problems.tree import Node

'''
Tree #1:

        5
      /   \
    3       8
  /   \    /  \
 12    10 2     7
         / \
        6   18
'''

'''
Naive Method that uses an array of nodes to store the path to each node p and q.
''' 
def first_common_ancestor1(tree, p, q):

    def find(tree, value, prev=[]):

        if tree == None: return None

        if tree.data == value:
            return prev + [tree.data]

        left = find(tree.left, value, prev + [tree.data])

        if left: return left

        right = find(tree.right, value, prev + [tree.data])

        if right: return right

    if not tree or not q or not p: return None

    p_path, q_path = find(tree, p), find(tree, q)

    if not (p_path and q_path): return None

    ancestor, index = None, 0
    
    while p_path[index] == q_path[index]:
        ancestor = p_path[index]
        index += 1

    return ancestor if ancestor else None

tree = Node(5)

tree.left = Node(3)
tree.left.left = Node(12)
tree.left.right = Node(10)

tree.right = Node(8)
tree.right.left = Node(2)
tree.right.left.left = Node(6)
tree.right.left.right = Node(18)

tree.right.right = Node(7)

fca1 = first_common_ancestor1(tree, 2, 7)

print(tree)

