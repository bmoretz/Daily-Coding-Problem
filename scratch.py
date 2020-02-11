from collections import defaultdict

from problems.graph import search, has_cycle
from problems.graph.adj_mat_graph import AMGraph
from problems.graph.adj_list_graph import ALGraph

'''Remove edges to create even trees.

You are given a tree with an even number of nodes. Consider each connection between a parent and child node to be an "edge".

You would like to remove some of these edges, such that the disconnected subtrees that remain each have an even number of nodes.

For example, supose your input is the following tree:

        1
      /   \
    2      3
         /   \
       4       5
     / | \
    6  7  8

In this case, if we remove the edge (3, 4), both resulting subtrees will be even.

Write a funciton that returns the maximum number of edges you can remove while still satisfying this requirement.
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

graph = AMGraph(graph_4)

verts = graph.vertices()
edges = graph.edges()
print(edges)

bn = graph.neighbors('b')

cycle = has_cycle(graph)

graph.add_vertex('g')
graph.add_edge(('a', 'g'))
print(edges)

