'''
In this programming problem you'll code up Prim's minimum spanning tree algorithm.

This file describes an undirected graph with integer edge costs. It has the format

[number_of_nodes] [number_of_edges]

[one_node_of_edge_1] [other_node_of_edge_1] [edge_1_cost]

[one_node_of_edge_2] [other_node_of_edge_2] [edge_2_cost]

...

For example, the third line of the file is "2 3 -8874", indicating that there is an edge connecting vertex #2 and vertex #3 that has cost -8874.

You should NOT assume that edge costs are positive, nor should you assume that they are distinct.

Your task is to run Prim's minimum spanning tree algorithm on this graph. You should report the overall cost of a minimum spanning tree --- an integer, 
which may or may not be negative --- in the box below.

IMPLEMENTATION NOTES: This graph is small enough that the straightforward O(mn) time implementation of Prim's algorithm should work fine. 

OPTIONAL: For those of you seeking an additional challenge, try implementing a heap-based version. The simpler approach, which should already give you a healthy
speed-up, is to maintain relevant edges in a heap (with keys = edge costs). The superior approach stores the unprocessed vertices in the heap, as described in 
lecture. Note this requires a heap that supports deletions, and you'll probably need to maintain some kind of mapping between vertices and their positions in the heap.
'''

import os

data_dir = os.getcwd() + '\\data\\illuminated\\prim-mst\\'

submission_file_path = data_dir + 'edges.txt'
test_file_path = data_dir + 'problem15.9test.txt'

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
        vert_count, edge_count = lines[0].split(' ')

        g = CostGraph()

        for line in lines[1:]:
            u, v, c = [int(d) for d in line.split(' ')]

            g.add_connection(u, v, c)

        assert len(g.vertices()) == int(vert_count)
        assert len(g.edges()) // 2 == int(edge_count)

    return g

def prim_slow(g):

    if not g: return None

    mst = {} # minimum spanning tree
    to_visit = []
    
    n = len(g.vertices()) - 1

    # pick an arbitrary vertex from s to start
    s = g.vertices()[0]

    while n != 0:

        # add all of s's edges
        for v, c in g[s].get_edges():
            # unless its already in the mst
            if v in mst:
                continue

            to_visit += [(v, c)]

        # sort all pending edges by minimum weight
        to_visit = sorted(to_visit, key=lambda n: n[1])

        # lowest cost edge is next
        v, c = to_visit[0]

        # remove the edge we are going to visit from
        # the queue of edge/cost pairs.
        to_visit = [(e, c) for e, c in to_visit if e != v]

        # save edge & cost
        mst[s] = c

        # visit and continue
        s = v
        n -= 1

    cost = 0

    for e in mst:
        cost += mst[e]

    return cost

def prim_fast(g):

    if not g: return None

    mst = set()
    costs = []
    
    n = set(g.vertices())

    # pick an arbitrary vertex from s to start
    s = g.vertices()[0]
    mst.add(s)

    # to visit heap
    to_visit = []

    while mst != n:

        # add all of s's edges
        for v, c in g[s].get_edges():
            # unless its already in the mst
            if v in mst:
                continue

            heapq.heappush(to_visit, (c, v))

        # keep taking lowest cost edges until
        # we have one that isn't part of
        # the MST
        while True:
            c, v = to_visit[0]
            heapq.heappop(to_visit)

            if v not in mst:
                break
        
        costs += [c]
        mst.add(v)

        s = v

    return sum(costs)

def benchmark_prim(iters=30):
    import time

    g = read_cost_graph_data(submission_file_path)

    for approach in [prim_slow, prim_fast]:

        times = []

        for _ in range(iters):

            start = time.time()
            
            approach(g)

            end = time.time()

            times += [end - start]

        avg_time = sum(times)/len(times)

        print(f'{approach.__name__} - Results: Ran {iters} iterations with average execution time: {avg_time}.')

benchmark_prim()

# prim_slow - Results: Ran 30 iterations with average execution time: 0.3260332743326823.
# prim_fast - Results: Ran 30 iterations with average execution time: 0.004483270645141602. - nice.
