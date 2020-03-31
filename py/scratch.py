'''Random Node.

You are implementing a binary tree class from scratch which, in
addition to insert, find, and delete, has a method getRandomNode()
which returns a random node from the tree. All nodes should be equally
likely to be chosen. Design and implement an algorithm for getRandomNode, 
and explain how you would implement the rest of the methods.
'''

from random import uniform

from problems.tree import Node

class RandomBinaryTree1():

    class TreeNode():

        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

        def is_full(self):
            return self.left and self.right

        def is_leaf(self):
            return not (self.left or self.right)

    def __init__(self):
        self.root = None

    def insert(self, data):
        if data == None: return None

        node = self.TreeNode(data)
        
        if self.root == None:
            self.root = node
        else:
            current = self.root
            
            while True:
                prev = current

                if data <= current.data:
                    if current.left == None:
                        current.left = node
                        break
                    if current.right == None:
                        current.right = node
                        break
                    
                    current = current.left

                elif data > current.data:
                    if current.left == None:
                        current.left = node
                        break
                    elif current.right == None:
                        current.right = node
                        break

                    current = current.right

            
    def find(self, value):
        
        def find_node(node, value):
            
            if node == None: 
                return None

            if node.data == value:
                return node

            left = find_node(node.left, value)

            if left: return left
 
            right = find_node(node.right, value)

            if right: return right

        if value == None: return None 

        return find_node(self.root, value)
    
    def delete(self, value):
        
        def delete_node(node, value, parent=None):

            if node == None: return

            if node.data == value:
                new_node = None

                if node.right and node.left:
                    new_node = node.right

                    current = node.right
                    prev = None

                    while current != None:
                        prev = current
                        current = current.left
                    
                    prev.left = node.left
                elif node.left and not node.right:
                    new_node = node.left
                elif not node.left and node.right:
                    new_node = node.right

                if parent == None:
                    self.root = new_node
                else:
                    
                    if node == parent.left:
                        parent.left = new_node
                    elif node == parent.right:
                        parent.right = new_node
    
            else:
                delete_node(node.left, value, node)
                delete_node(node.right, value, node)
                
        if value == None: return None

        return delete_node(self.root, value)

    def __get_values(self):

        def subvalues(node):

            if node == None: return

            values = []

            if node.left:
                values += subvalues(node.left)

            values += [node.data]

            if node.right:
                values += subvalues(node.right)
            
            return values

        if self.root == None: return []

        return subvalues(self.root)

    def get_random_node(self):
        
        if self.root == None: return None

        values = self.__get_values()

        index = int(uniform(0, len(values)))

        return values[index]

tree = BinaryTree()

tree.insert(40)
tree.insert(30)
tree.insert(60)
tree.insert(10)
tree.insert(20)
tree.insert(50)
tree.insert(70)

val = tree.find(10)

print(tree.get_random_node())

tree.delete(10)

print(tree.get_random_node())

tree.delete(40)

print(tree.get_random_node())

print(tree)
