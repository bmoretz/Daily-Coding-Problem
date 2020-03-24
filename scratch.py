'''List of Depths.

Given a binary tree, design an algorithm which creates a linked list of all the nodes
at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
'''

class DepthList1():

    class Node():
        def __init__(self, data):
            self.data = data
            self.next = None

    class BinaryTree():

        class Node():
            def __init__(self, data):
                self.data = data
                self.left = None
                self.right = None
                
        def __init__(self, values):
            self.root = None

            if len(values) > 0:
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

        def height(self, node=None, level=0):
            
            if level == 0:
                node = self.root

            if node == None:
                return level

            level = max(self.height(node.left, level + 1), self.height(node.right, level + 1))

            return level

    def __init__(self, values):

        self.tree = None

        if values != None:
            self.tree = self.BinaryTree(values)

    def process_level(self, nodes):
        
        children = []
        head, prev = None, None

        for node in nodes:
            
            ln = self.Node(node.data)

            if head == None:
                head, prev = ln, ln
            else:
                prev.next = ln

            if node.left: children.append(node.left)
            if node.right: children.append(node.right)

            prev = ln
        
        return (head, children)

    def depth_list(self):
        
        levels, nodes = [], [self.tree.root]

        while nodes:

            lvl = self.process_level(nodes)

            levels.append(lvl[0])
            nodes = lvl[1]

        return levels

values = [1, 2, 3, 4, 5, 6, 7]

dl = DepthList1(values)

height = dl.tree.height()

elements = dl.depth_list()

print(elements)