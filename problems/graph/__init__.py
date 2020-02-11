from collections import defaultdict

from interface import Interface

class InvalidState(ValueError):
    """Exception raised when the state is invalid."""
    
    def __repr__(self):
        return 'The state of the graph is invalid for this operation.'

class IGraph(Interface):

    def vertices(self):
        """ returns the verticies of the graph.""" 
        pass

    def edges(self):
        """ return the edges of the graph. """
        pass
    
    def neighbors(self, vertex):
        """ return the neighbors of a given vertex. """
        pass

    def add_vertex(self, vertex):
        """ If the vertex, "vertex", is not in
        the graph, a new "vertex" with an empty
        association is added to the dictionary.
        """
        pass

    def add_edge(self, edge):
        """
        """
        pass

def search(graph : IGraph, vertex, visited, parent):
    """ depth-first search the given graph."""

    visited[vertex] = True

    for neighbor in graph.neighbors(vertex):

        if not visited[neighbor]:
            if search(graph, neighbor, visited, vertex):
                return True

        elif parent != neighbor:
            return True

    return False

'''Determine if a cycle exists.

Given an undirected graph, determine if it contains a cycle.
'''

def has_cycle(graph):
    """Static method to determine if the graph contains a cycle."""
    visited = { v : False for v in graph.vertices()}

    for vertex in graph.vertices():
        if not visited[vertex]:
            if search(graph, vertex, visited, None):
                return True

    return False