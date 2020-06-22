'''
In this programming problem and the next you'll code up the greedy algorithm from the lectures on Huffman coding.

This file describes an instance of the problem. It has the following format:

[number_of_symbols]

[weight of symbol #1]

[weight of symbol #2]

...

For example, the third line of the file is "6852892," indicating that the weight of the second symbol of the alphabet is 6852892. 
(We're using weights instead of frequencies, like in the "A More Complex Example" video.)

Your task in this problem is to run the Huffman coding algorithm from lecture on this data set. 

What is the maximum length of a codeword in the resulting Huffman code?
'''

import os
import heapq
from collections import defaultdict

data_dir = os.getcwd() + '\\data\\illuminated\\huffman-coding\\'

submission_file_path = data_dir + 'huffman.txt'
test_file_path = data_dir + 'problem14.6test1.txt'

class TreeNode():

    def __init__(self, cost, left=None, right=None, parent=None):
        self.cost = cost
        self.left = left
        self.right = right
        self.parent = parent

    def depth(self):

        node, depth = self.parent, 0

        while node.parent:
            node = node.parent
            depth += 1

        return depth

    def get_encoding(self):
        
        node, cost = self.parent, self.cost
        value = []

        while node:
            value.insert(0, 1 if node.left == cost else 0)
            node, cost = node.parent, node.cost
        
        return value

    def is_leaf(self):
        return not( self.left or self.right )

    def __lt__(self, other):

        if isinstance(other, TreeNode):
            return self.cost < other.cost
        elif isinstance(other, int):
            return self.cost < other
        else:
            return NotImplemented()

    def __eq__(self, other):
        if isinstance(other, TreeNode):
            return self.cost == other.cost
        elif isinstance(other, int):
            return self.cost == other
        else:
            return NotImplemented()

    def __gt__(self, other):
        if isinstance(other, TreeNode):
            return self.cost > other.cost
        elif isinstance(other, int):
            return self.cost > other
        else:
            return NotImplemented()

    def __hash__(self):
        return self.cost

    def __str__(self):
        return str(self.cost)

def traverse(root):

    current_level = [root]

    while current_level:

        print(' '.join(('\t'*node.depth() + str(node)) for node in current_level))
        next_level = list()
        for n in current_level:
            if n.left:
                next_level.append(n.left)
            if n.right:
                next_level.append(n.right)

        current_level = next_level

def merge(left : TreeNode, right : TreeNode) -> TreeNode:

    new_cost = left.cost + right.cost

    merged = TreeNode(new_cost, left=left, right=right)

    left.parent = merged
    right.parent = merged

    del left, right

    return merged

def read_huffman_coding(file_path):

    with open(file_path, 'r') as f:

        lines = f.read().splitlines()

        weights = []

        for line in lines[1:]:
            heapq.heappush(weights, TreeNode(int(line)))

        return weights
        
def get_encoding_tree(weights):

    while len(weights) >= 2:
        
        node_a = heapq.heappop(weights)
        node_b = heapq.heappop(weights)

        merged = merge(node_a, node_b)

        heapq.heappush(weights, merged)

    root = weights[0]

    return root

def get_encodings(root : TreeNode):

    path = [root]
    encodings = []

    while path:

        node = path.pop()

        if node.is_leaf():
            encodings += [(node.cost, node.get_encoding())]

        if node.left:
            path += [node.left]
    
        if node.right:
            path += [node.right]

    return sorted(encodings, key=lambda k: k[1])

def run_huffman_coding(file_path):

    weights = read_huffman_coding(file_path)

    root = get_encoding_tree(weights)    

    # optional, we can also get the number of encodings by simply
    # looking at the min/max depth of the tree.
    encodings = get_encodings(root)

    minimum, maximum = min(encodings, key=lambda k: len(k[1])), max(encodings, key=lambda k: len(k[1]))

    print(f'low - {minimum[1]} ({len(minimum[1])}), high - {maximum[1]} ({len(maximum[1])})')


run_huffman_coding(submission_file_path)