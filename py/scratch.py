'''BiNode.

Consider a simple data structure called BiNode, which has pointers
to two other nodes.

The data structure BiNode could be used to represent both a binary
tree (where node1 is the left node and node2 is the right node) or
a doubly linked list (where node1 is the previous node and node2
is the next node). Implement a method to convert a binary search
tree (implemented with BiNode) into a doubly linked list. The
values should be kept in order and the operation should be
performed in place (that is, on the original data structure).
'''

class TreeToList():

    class NodePair():

        def __init__(self, head=None, tail=None):
            self.head = head
            self.tail = tail

    class BiNode():

        def __init__(self, data=None, node1=None, node2=None):
            self.data = data
            self.node1 = node1
            self.node2 = node2

        def __str__(self):
            return f'{self.data}'

    @staticmethod
    def to_list(node):
        
        if not node: return None

        part1 = to_list(node.node1)
        part2 = to_list(node.node2)
        
        if part1:
            concat(part1.tail, node)

        if part2:
            concat(node, part2.head)

        return NodePair(node if not part1 else part1.head,
                    node if not part2 else part2.tail)

    @staticmethod
    def concat(x, y):
        x.node2 = y
        y.node1 = x

    @staticmethod
    def build_tree(arr):

        n = len(arr)
        
        if n == 0: return None

        mid = n//2

        node = BiNode(arr[mid])

        if n > 0: node.node1 = build_tree(arr[:mid])
        if n > 1: node.node2 = build_tree(arr[mid + 1:])

        return node

    @staticmethod
    def flatten(node):

        arr = []
        while node:
            arr.append(node.data)
            node = node.node2

        return arr

arr = list(range(1, 12))

tree = build_tree(arr)

lst = to_list(tree)

print()