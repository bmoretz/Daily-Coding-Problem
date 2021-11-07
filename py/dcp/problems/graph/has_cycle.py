from .common import IGraph, search

"""
Determine if a cycle exists.

Given an undirected graph, determine if it contains a cycle.
"""

def has_cycle(graph : IGraph):
    ''' determine if the graph contains a cycle '''
    visited = { v : False for v in graph.vertices()}

    for vertex in graph.vertices():
        if not visited[vertex]:
            if search(graph, vertex, visited, None):
                return True

    return False