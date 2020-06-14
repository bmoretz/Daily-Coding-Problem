'''
In this programming problem and the next you'll code up the clustering algorithm from lecture for computing a max-spacing kk-clustering.

This file describes a distance function (equivalently, a complete graph with edge costs). It has the following format:

[number_of_nodes]

[edge 1 node 1] [edge 1 node 2] [edge 1 cost]

[edge 2 node 1] [edge 2 node 2] [edge 2 cost]

...

There is one edge (i,j)(i,j) for each choice of n 1 ≤i < j ≤ n, where n is the number of nodes.

For example, the third line of the file is "1 3 5250", indicating that the distance between nodes 1 and 3 (equivalently, the cost of the edge (1,3)) is 5250. 
You can assume that distances are positive, but you should NOT assume that they are distinct.

Your task in this problem is to run the clustering algorithm from lecture on this data set, where the target number kk of clusters is set to 4. What is the maximum spacing of a 4-clustering?

ADVICE: If you're not getting the correct answer, try debugging your algorithm using some small test cases. And then post them to the discussion forum!
'''

import os

data_dir = os.getcwd() + '\\data\\illuminated\\clustering\\one\\'

submission_file_path = data_dir + 'clustering1.txt'
test_file_path = data_dir + 'input_completeRandom_1_8.txt'

from collections import defaultdict
import heapq

class CostGraph():

    class Node():
        '''
        each node has edges (keys) and weights (cost for v -> u)
        '''
        def __init__(self):
            self.edges = {}
        
        def add_edge(self, v, c):
            self.edges[v] = c

        def get_edges(self):

            edges = []

            for w in self.edges:
                # edge & cost
                edges += [(w, self.edges[w])]
            
            return edges

    def __init__(self):
        self.nodes = defaultdict(self.Node)

    def add_connection(self, u, v, c):
        self.nodes[u].add_edge(v, c)
        self.nodes[v].add_edge(u, c)

    def vertices(self):
        return list(self.nodes.keys())

    def edges(self):
        e = []
        for w in self.nodes:
            for v in self.nodes[w].edges:
                e += [(w, v)]
        return e
    
    def __getitem__(self, key):
        return self.nodes[key]

def read_cost_graph_data(file_path):
    ''' read cost graph

    this function reads a cost graph from
    a definition file where the first row
    contains the # nodes / # edges, rows
    2:n contain edges in v, u, c format.
    '''

    with open(file_path, 'r') as f:

        lines = f.read().splitlines()
        vert_count = int(lines[0])

        g = CostGraph()

        for line in lines[1:]:
            u, v, c = [int(d) for d in line.split(' ')]

            g.add_connection(u, v, c)

        assert len(g.vertices()) == int(vert_count)

    return g

class UnionFind:
    _n = 0
    _number_unions = 0

    def __init__(self):
        self.parent = self
        self.rank = 0
        self._inc_groups()

    @classmethod
    def _inc_groups(cls):
        cls._n += 1


def find(x):
    # this is used exclusively to find if 2 objects belong to the same set
    if x.parent != x:
        x.parent = find(x.parent)
    return x.parent

def _link(x, y):
    if x.rank < y.rank:
        x.parent = y
    else:
        y.parent = x
        if x.rank == y:
            x.rank += 1

def union(x, y):
    a = find(x)
    b = find(y)
    if a != b:
        UnionFind._number_unions += 1
        _link(find(x), find(y))

def groups():
    return UnionFind._n - UnionFind._number_unions

def k_cluster(g, k) -> int:
    
    def get_distances(g):
        distances = []

        seen = defaultdict(set)

        for node in g.nodes:
            for neighbor in g[node].edges:

                if neighbor in seen[node]:
                    continue

                cost = g[node].edges[neighbor]
                distances += [(cost, node, neighbor)]
                seen[neighbor].add(node)

        return sorted(distances)

    component = defaultdict(set)

    # initial clusters
    for node in g.nodes:
        component[node].add(node)

    distances = get_distances(g)

    while k < len(component):
        
        _, u, v = distances[0]

        if component[u] != component[v]:

            for w in g.nodes:

                if component[w] == component[v]:
                    component[w] = component[u] 

        del distances[0]

    min_spacing, _, _ = distances[0]

    return min_spacing

g = read_cost_graph_data(test_file_path)

c = k_cluster(g, k=4)

print(c)