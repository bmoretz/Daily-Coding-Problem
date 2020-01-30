
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


'''7.1

Find floor and ceiling.

Given a binary search tree, find the floor and ceiling of a given integer. The floor is the highet element in the tree less than or equal to an integer, while the ceiling is the lowest element in the tree greater than or equal to an integer.

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