'''
In this question your task is again to run the clustering algorithm from lecture, but on a MUCH bigger graph. So big, in fact, that the distances (i.e., edge costs) are only defined implicitly, rather than being provided as an explicit list.

The data set is below.

clustering_big.txt
The format is:

[# of nodes] [# of bits for each node's label]

[first bit of node 1] ... [last bit of node 1]

[first bit of node 2] ... [last bit of node 2]

...

For example, the third line of the file "0 1 1 0 0 1 1 0 0 1 0 1 1 1 1 1 1 0 1 0 1 1 0 1" denotes the 24 bits associated with node #2.

The distance between two nodes uu and vv in this problem is defined as the Hamming distance--- the number of differing bits --- between 
the two nodes' labels. For example, the Hamming distance between the 24-bit label of node #2 above and the label 
"0 1 0 0 0 1 0 0 0 1 0 1 1 1 1 1 1 0 1 0 0 1 0 1" is 3 (since they differ in the 3rd, 7th, and 21st bits).

The question is: what is the largest value of kk such that there is a kk-clustering with spacing at least 3? That is, how many clusters 
are needed to ensure that no pair of nodes with all but 2 bits in common get split into different clusters?

NOTE: The graph implicitly defined by the data file is so big that you probably can't write it out explicitly, let alone sort the edges 
by cost. So you will have to be a little creative to complete this part of the question. For example, is there some way you can identify
the smallest distances without explicitly looking at every pair of nodes?'''

import os

data_dir = os.getcwd() + '\\data\\illuminated\\clustering\\two\\'

submission_file_path = data_dir + 'clustering_big.txt'
test_file_path = data_dir + 'input_random_10_16_18.txt'

class UnionFind:

    def __init__(self, nodes):
        self.nodes = nodes
        self.leaders = dict()
        self.members = dict()

        for node in nodes:
            # Keeps mapping of leaders to groups
            if str(node) not in self.leaders:
                self.leaders[str(node)] = [node]
            # Account for duplicate node ids
            else:
                self.leaders[str(node)].append(node)
            # Keeps mapping of nodes to leaders
            self.members[str(node)] = node

    def find(self, node):
        return self.members[str(node)]

    def union(self, node1, node2):
        # Find our two groups and decide which should be merged into which by
        # size of group
        (old_leader, new_leader) = sorted((self.find(node1), self.find(node2)),
                                          key = lambda x:
                                                len(self.leaders[str(x)]))

        # If these two nodes were already in the same group we are finished
        if old_leader == new_leader:
            return
        else:
            # Add the old group the new group
            old_group = self.leaders.pop(str(old_leader))
            self.leaders[str(new_leader)].extend(old_group)

            # Reassign the leaders in the old group
            for node in old_group:
                self.members[str(node)] = new_leader

def read_hamming(path):
    
    with open(path, 'r') as handle:
        lines = handle.readlines()

    n_nodes, n_bits = lines.pop(0).split(' ', 1)
    nodes = list()
    
    for index, line in enumerate(lines):
        node_bits = bytearray([int(index) for index in line.split(' ', int(n_bits) - 1)])
        nodes.append(node_bits)

    return nodes

def hamming_possibilities(node, distance):
    from itertools import combinations
    import copy
    '''
    Calculate all possible nodes within a hamming distance of node
    '''
    ids = combinations(range(len(node)), distance)
    
    nodes = list()
    for shift in ids:
        new = copy.copy(node)
        for pos in shift:
            new[pos] = not node[pos]
        nodes.append(new)
    return nodes

def minimum_clusters(nodes, spacing=2):
    '''
    Find the minimum clusters needed to have a specific spacing
    '''
    union = UnionFind(nodes)
    for i in range(1, spacing+1):
        for node in union.nodes:
            closest = hamming_possibilities(node, i)
            for partner in closest:
                try:
                    union.union(node, partner)
                except KeyError:
                    pass
    return len(union.leaders)

nodes = read_hamming(submission_file_path)

print(minimum_clusters(nodes))