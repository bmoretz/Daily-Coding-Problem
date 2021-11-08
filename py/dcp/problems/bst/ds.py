
'''Generic BST Node'''

class Node:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right

'''BST Helper Class'''
class BST:

    def __init__(self):
        self.root = None

    def insert(self, x):
        if not self.root:
            self.root = Node(x)
        else:
            self._insert(x, self.root)

    def _insert(self, x, root):
        if x < root.data:
            if not root.left:
                root.left = Node(x)
            else:
                self._insert(x, root.left)
        else:
            if not root.right:
                root.right = Node(x)
            else:
                self._insert(x, root.right)


    def find(self, x):
        if not self.root:
            return False
        else:
            return self._find(x, self.root)

    def _find(self, x, root):
        if not root:
            return False
        elif x == root.data:
            return True
        elif x < root.data:
            return self._find(x, root.left)
        else:
            return self._find(x, root.right)

'''Build BST.

Given a sorted array, convert it into a hight-balanced binary search tree.

'''

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