from collections import defaultdict

from problems.graph import IGraph
from problems.graph.adj_list_graph import ALGraph
from problems.graph.adj_mat_graph import AMGraph

''' Remove edges to create even trees.

You are given a tree with an even number of nodes. Consider each connection between a parent and child node to be an "edge". You
would like to remove some of these edges, such that the disconnected subtrees that remain each have an even number of nodes.

For example, suppose your input is the following tree:

        1
      /   \
    2      3
          /  \
         4    5
       / | \
      6  7  8

In this case, if we remove the edge (3, 4), both resulting subtrees will be even.

Write a function that returns the maximum number of edges you can remove while still satisfying this requirement.
'''

graph_4 = {
    1 : [2, 3],
    2 : [],
    3 : [4, 5],
    4 : [6, 7, 8],
    5 : [],
    6 : [],
    7 : [],
    8 : [],
}

graph = ALGraph(graph_4)

def max_edges2(graph : IGraph):

    def child_count(graph : IGraph, current, counts=None):

        if not counts:
            counts = defaultdict(int)

        if not counts[current]: counts[current] = 0

        for neighbor in graph.neighbors(current):

            if not counts[neighbor]:
                child_count(graph, neighbor, counts)
                counts[current] += 1

            counts[current] += counts[neighbor]

        return counts

    counts = child_count(graph, graph.root())


    return counts


counts = max_edges2(graph)


print(counts)