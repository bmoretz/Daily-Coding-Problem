from collections import defaultdict

from .common import IGraph

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

def max_edges1(graph):

    def traverse(graph : IGraph, cur, result):
        descendants = 0

        for child in graph.neighbors(cur):
            num_nodes, result = traverse(graph, child, result)

            result[child] += num_nodes - 1
            descendants += num_nodes

        return descendants + 1, result

    start = graph.root()
    vertices = defaultdict(int)

    _, descendants = traverse(graph, start, vertices)

    return len([val for val in descendants.values() if val % 2 == 1])