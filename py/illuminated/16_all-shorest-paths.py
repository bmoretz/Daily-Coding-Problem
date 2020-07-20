'''
In this assignment you will implement one or more algorithms for the all-pairs shortest-path problem. Here are data files describing three graphs:

The first line indicates the number of vertices and edges, respectively. Each subsequent line describes an edge (the first two numbers are its tail and head, respectively) 
and its length (the third number). NOTE: some of the edge lengths are negative. NOTE: These graphs may or may not have negative-cost cycles.

Your task is to compute the "shortest shortest path". Precisely, you must first identify which, if any, of the three graphs have no negative cycles. For each such graph, 
you should compute all-pairs shortest paths and remember the smallest one (i.e., compute \min_{u,v \in V} d(u,v)min u,v ∈ V d(u,v), where d(u,v)d(u,v) denotes the shortest-path distance from uu to vv).

If each of the three graphs has a negative-cost cycle, then enter "NULL" in the box below. If exactly one graph has no negative-cost cycles, then enter the length of its shortest shortest 
path in the box below. If two or more of the graphs have no negative-cost cycles, then enter the smallest of the lengths of their shortest shortest paths in the box below.

OPTIONAL: You can use whatever algorithm you like to solve this question. If you have extra time, try comparing the performance of different all-pairs shortest-path algorithms!

OPTIONAL: Here is a bigger data set to play with.
'''

import os, math
from collections import defaultdict
from heapq import heappop, heappush

import numpy as np
from tqdm import tqdm

data_dir = os.getcwd() + '\\data\\illuminated\\shortest-paths\\'

submission_file_paths = [data_dir + sub for sub in ['g1.txt', 'g2.txt', 'g3.txt']]
big_submission_file_path = data_dir + 'large.txt'

test_file_path = data_dir + 'problem18.8test1.txt'

def bellman_ford(graph, graph_inverted):
    """
    Implementation of the Bellman-Ford algorithm to find the single-source shortest path for a graph possibly containing
    negative edges.
    """
    
    print('creating modified graph by adding artificial start vertex s (id=0) with zero-edge to each vertex')

    s = 0
    graph_ = defaultdict(set, graph)
    graph_inverted_ = defaultdict(set, graph_inverted)

    for vertex in graph.keys():
        graph_[s].add(vertex)
        graph_inverted_[vertex].add((0, s))

    n = len(graph_)
    A = np.full(n, np.inf)
    A[s] = 0

    # we don't need to compute the full DP matrix, only the last 2 columns
    arrays_are_equal = False
    for _ in tqdm(range(1, n + 1)):
        A_next = np.full(n, np.inf)
        for v in graph.keys():
            case_1 = A[v]

            if v in graph_inverted:
                # v has incoming edges from vertices w: compute path to v with at most i-1 edges from all ws
                case_2 = min(A[w] + c for (c, w) in graph_inverted[v])
            else:
                case_2 = math.inf

            A_next[v] = min(case_1, case_2)

        arrays_are_equal = np.array_equal(A, A_next)
    
        if arrays_are_equal:
            print('early stopping because no change in previous iteration')
            return A[1:]

        A = A_next

    if not arrays_are_equal:
        print('negative cycle detected in additional iteration')
        return None

    print('no negative cycle detected')
    return A[1:]

def dijkstra(graph, s, t):
    """
    Heap-based implementation of Dijkstra's algorithms for SSSP for a given source vertex s and target vertex t
    :param graph: graph as dictionary mapping the edges for each vertex as follows:
                    source_vertex -> {(cost, target_vertex}
    :param s: start vertex
    :param t: target vertex
    :return: the cost and path of the minimal path from s to t if there is one, else infinity
    """
    q, seen, mins = [(0, s, ())], set(), {s: 0}
    while q:
        (cost, v1, path) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            path = (v1, path)
            if v1 == t:
                return cost, path

            for c, v2 in graph.get(v1, ()):
                if v2 in seen:
                    continue
                prev = mins.get(v2, None)
                next = cost + c
                if prev is None or next < prev:
                    mins[v2] = next
                    heappush(q, (next, v2, path))

    return float("inf")

def johnson(filename):

    print(f'processing {filename}')
    
    with open(filename) as f:
        lines = f.readlines()

    n_vertices, n_edges = map(int, lines[0].split())
    
    print(f'number of vertices: {n_vertices}')
    print(f'number of edges: {n_edges}')

    # create graph as dict: source -> (cost, target)
    graph = defaultdict(set)
    graph_inverted = defaultdict(set)  # precompute incoming edges for performance speedup
    
    for line in lines[1:]:
        u, v, c = map(int, line.split())
        graph[u].add((c, v))
        graph_inverted[v].add((c, u))

    assert len(graph.keys()) == n_vertices, 'length of vertices does not match'
    assert len(list(edge for edges in graph.values() for edge in edges)) == n_edges, 'length of edges does not match'

    print('running Bellman-Ford once to get single-source shortest path for a graph with possibly negative edges')
    
    A = bellman_ford(graph, graph_inverted)
    
    if A is None:
        # negative cost cycle detected
        return math.inf

    return min(A)

for s in submission_file_paths:
    print(f'{s}: {johnson(s)}')