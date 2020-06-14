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
    '''
    An implementation of union-find data structure by rank.
    '''
    
    def __init__(self, n):
        '''
        Initialize an union-find with n items(objects).
        '''
        self.root = list(range(n))
        self.rank = [0]*n
        self.num = n # the number of clusters
    
    def find(self, x):
        '''
        Find the root(pointer) of the item x. Using path compression.
        '''
        s_list = self.root

        if s_list[x] != x:
            s_list[x] = self.find(s_list[x])

        return s_list[x]
    
    def count(self):
        return self.num
        
    def union(self, x,y):
        '''
        Union x and y.
        '''
        s = self.root
        rank_list = self.rank
        
        s1 = self.find(x)
        s2 = self.find(y)
        
        if s1 == s2:
            return
        
        self.num -= 1

        if rank_list[s1] == rank_list[s2]:
            s[s2] = s1
            rank_list[s1] +=1
        elif rank_list[s1]>rank_list[s2]:
            s[s2] = s1
        else:
            s[s1] = s2
            
    def connected(self, x, y):
        '''
        Check if x and y are in the same cluster.
        '''
        return self.find(x) == self.find(y)

def get_distances(g):
    distances = []
    seen = defaultdict(set)

    for node in g.nodes:
        for neighbor in g[node].edges:

            if neighbor in seen[node]:
                continue

            cost = g[node].edges[neighbor]
            heapq.heappush(distances, (cost, node, neighbor))
            seen[node].add(neighbor)

    return sorted(distances)

'''
k clustering algorithm

first sort the graph edges by smallest distance
initialize union find to number of vertices

iterate the edges in order of smallest distance
if the components u, v are not connected (live
in the same component), connect them via union.

once we are down to k components, the next
non-connected edge weight is the maximum
spacing of said graph.
'''

def k_cluster(g, k) -> int:

    distances = get_distances(g)
    components = UnionFind(len(g.vertices()) + 1)

    min_spacing = None

    # build clusters until we have
    # k components
    while components.count() != k:

        cost, u, v = distances[0]
        heapq.heappop(distances)

        if not components.connected(u, v):
            components.union(u, v)

    min_spacing = None

    # min spacing is the cost of the next
    # non-connected component
    while True:
        cost, u, v = distances[0]
        heapq.heappop(distances)

        if not components.connected(u, v):
            min_spacing = cost
            break

    return min_spacing
        
g = read_cost_graph_data(submission_file_path)

c = k_cluster(g, k=4)

print(c)