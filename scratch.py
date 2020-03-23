'''Minimal Tree.

Given a sorted (increasing order) array with unique integer elements, write
an algorithm to create a binary search tree with minimal height.
'''

class MinTree1():

    class Node():

        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None
        
        def is_full(self):
            return self.left != None and self.right != None

        def is_leaf(self):
            return self.left == None and self.right == None

    def __init__(self, values):
        
        self.root = None
        
        if values == None: return

        self.root = self.__create_tree(values)

    def __create_tree(self, values):
        
        n = len(values)

        if n == 0: return None

        mid = n // 2

        root = self.Node(values[mid])

        if n > 1:
            root.left = self.__create_tree(values[:mid])
            root.right = self.__create_tree(values[mid + 1:])

        return root

    def height(self):

        def height(self, parent, level=0):
            
            if parent == None: 
                return level

            level = max(height(self, parent.left, level + 1), height(self, parent.right, level + 1))

            return level

        return height(self, self.root)

# values = [1, 2, 3, 4, 5, 6]

mt = MinTree1([1, 2, 3, 4, 5, 6, 7])

h = mt.height()

print(mt)