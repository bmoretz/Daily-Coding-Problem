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
test_file_path = data_dir + 'input_completeRandom_6_4.txt'

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


def cluster(g, k) -> int:
    
    c = defaultdict(set)

    # initial clusters
    for node in g.nodes:
        c[node] = [node]

    distances = []

    seen = defaultdict(set)

    for node in g.nodes:
        for neighbor in g[node].edges:

            if neighbor in seen[node]:
                continue

            cost = g[node].edges[neighbor]
            heapq.heappush(distances, (cost, node, neighbor))
            seen[neighbor].add(node)

    merged = {}

    while k < len(c):
        
        _, u, v = distances[0]
        heapq.heappop(distances)

        if u in merged:
            if v in merged[u]:
                continue

            u = merged[u]

        if v in merged:
            v = merged[v]

        if u == v: continue

        for node in g.nodes[v].edges:
            
            if node == u:
                continue
            
            if node in g.nodes[u].edges:
                u_cost = g[u].edges[node]
                v_cost = g[v].edges[node]

                g[u].edges[node] = min(u_cost, v_cost)
            else:
                g[u].edges[node] = g[v].edges[node]

        merged[v].add(u)
        c[u].add(v)

        if v in c:
            for m in c[v]:
                if m in c[u]:
                    continue
                c[u].append(m)

        if v in c:
            del c[v]
    
    min_spacing, _, _ = distances[0]

    return min_spacing

g = read_cost_graph_data(test_file_path)

c = cluster(g, k=3)

print(c)