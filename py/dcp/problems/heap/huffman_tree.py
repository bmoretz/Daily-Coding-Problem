'''Huffman tree.

Huffman coding is a method of encoding characters based on their frequency. Each letter is assigned a variable-length binary string, where shorter lengths ccorrespond to more common letters. 

To accomplish this, a binary tree is built such that the path from the root to any leaf uniquely maps to a character. When traversing the path, descending to a left child corresponds to a 0 in the prefix,
while descending right corresponds to 1.

'''

import heapq
from collections import defaultdict

class Node:
    def __init__(self, char, left=None, right=None):
        self.char = char
        self.left = left
        self.right = right

def huffman_coding1(value):

    def get_frequencies(value):
        freq = defaultdict(int)

        for val in value:
            freq[val] += 1

        return freq

    def build_tree(frequencies):
        nodes = []
        
        for char, frequency in frequencies.items():
            heapq.heappush(nodes, (frequency, Node(char)))

        while len(nodes) > 1:
            f1, n1 = heapq.heappop(nodes)
            f2, n2 = heapq.heappop(nodes)
            node = Node('*', left=n1, right=n2)
            heapq.heappush(nodes, (f1 + f2, node))

        root = nodes[0][1]

        return root

    def encode(root, string='', mapping={}):
        if not root:
            return

        if not root.left and not root.right:
            mapping[root.char] = string
        
        encode(root.left, string + '0', mapping)
        encode(root.right, string + '1', mapping)

        return mapping

    freq = get_frequencies(value)
    tree = build_tree(freq)
    encoded = encode(tree)

    return encoded