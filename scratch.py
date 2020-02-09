from collections import defaultdict

from problems.graph import Graph

'''Determine if a cycle exists.

Given an undirected graph, determine if it contains a cycle.
'''


"""
a       b
  \   / |
    c   |     f
  /   \ |
d       e
"""

graph_1 = { 
    "a" : ["c"],
    "b" : ["c", "e"],
    "c" : ["a", "b", "d", "e"],
    "d" : ["c"],
    "e" : ["c", "b"],
    "f" : []
}

"""
a       b
|   /\/
|   \c       f
|  /   \
d       e
"""

graph_2 = { 
    "a" : ["d"],
    "b" : ["c"],
    "c" : ["b", "c", "d", "e"],
    "d" : ["a", "c"],
    "e" : ["c"],
    "f" : []
}

def DFS(graph, start, visited=set()):
    visited.add(start)

    for neighbor in graph.neighbors(start):
        if neighbor not in visited:
            DFS(graph, neighbor, visited)

    return visited

graph = Graph(graph_1)

items = DFS(graph, "a")

print(graph)