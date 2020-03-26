'''Successor.

Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree.

You may assume that each node has a link to its parent.
'''

from problems.tree import Node

def successor(tree, value):

    def path(tree, value):

        if tree == None: return None

        path = []

        while tree != None:

            path.append(tree)

            if tree.data == value:
                break
            elif tree.data >= value:
                tree = tree.left
            elif tree.data < value:
                tree = tree.right
        
        return path

    if tree == None or value == None: return None

    target_path = path(tree, value)
    
    target = target_path.pop()

    #  node does not exist
    if target == None or target.data != value: return None

    if target.right == None:
        
        target = target_path.pop()

        while target.data < value and target_path:
            target = target_path.pop()

        return target if target_path else None
    else:
        nxt = target.right

        while nxt.left != None:
            nxt = nxt.left

        return nxt
'''
Tree :1

successor(20) == 21

          3
        /   \
      2      20
          /     \
        10        30
      /          /  \
    5          25    33
              /  \
            23   28
           /
          21
'''

tree = Node(3)

tree.left = Node(2)
tree.right = Node(20)

tree.right.left = Node(10)
tree.right.left.left = Node(5)

tree.right.right = Node(30)
tree.right.right.left = Node(25)

tree.right.right.left.left = Node(23)
tree.right.right.left.left.left = Node(21)
tree.right.right.left.right = Node(28)

tree.right.right.right = Node(33)

suc = successor(tree, 33)

print(tree)


assert successor(tree, 20).data == 21
assert successor(tree, 3).data == 5
assert successor(tree, 30).data == 33
