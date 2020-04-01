'''Paths with Sum.

You are given a binary tree in which each node contains an integer value
(which might be positive or negative). Design an algorithm to count the
number of of paths that sum to a given value. The path does not need to
start or end at the root or a leaf, but it must go downwards (traveling
only from parent nodes to child nodes).
'''

from problems.tree import Node

class SumTree():

    class TreeNode():

        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

        def path_sums(self, value):
        
            def child_sums(node, parent_sum):
                
                if node == None: return

                path_sum = parent_sum + node.data

                sums = 1 if path_sum == value else 0

                if node.left:
                    sums += child_sums(node.left, path_sum)    

                if node.right:
                    sums += child_sums(node.right, path_sum)

                return sums

            sums = 1 if self.data == value else 0

            if self.left:
                sums += child_sums(self.left, self.data)
            
            if self.right:
                sums += child_sums(self.right, self.data)
            
            return sums

    def __init__(self):
        self.root = None
    
    def insert_at(self, node, value):
        
        if node == None: return

        if value <= node.data:
            node.left = self.TreeNode(value)
        elif value >= node.data:
            node.right = self.TreeNode(value)

    def insert(self, value):

        def insertInOrder(node, value):
            
            if node == None: return

            if value <= node.data:
                if node.left == None:
                    node.left = self.TreeNode(value)
                else:
                    insertInOrder(node.left, value)
            elif node.data < value:
                if node.right == None:
                    node.right = self.TreeNode(value)
                else:
                    insertInOrder(node.right, value)

        if self.root == None:
            self.root = self.TreeNode(value)
        else:
            insertInOrder(self.root, value)


tree = SumTree()

#  [5, -5, 3, 2, -10, 10, 7, -3, -1, 6, 15, -5, 5, -15, -20]

values = [5, 8, 3, 7, 4, 10, 2]

for value in values:
    tree.insert(value)

tree.insert_at(tree.root.right.left, 3)

root_sums = tree.root.path_sums(8)

print(root_sums)