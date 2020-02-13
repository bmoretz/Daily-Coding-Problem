from collections import defaultdict

from interface import Interface

class InvalidState(ValueError):
    '''Exception raised when the state is invalid.'''
    
    def __repr__(self):
        return 'The state of the graph is invalid for this operation.'

class IGraph(Interface):

    def vertices(self):
        ''' returns the verticies of the graph.''' 
        pass

    def edges(self):
        ''' return the edges of the graph. '''
        pass
    
    def isolated(self):
        ''' returns isolated nodes in the graph. '''

    def neighbors(self, vertex):
        """ return the neighbors of a given vertex. """
        pass
    
    def add_vertex(self, vertex):
        ''' If the vertex, "vertex", is not in
        the graph, a new "vertex" with an empty
        association is added to the dictionary.
        '''
        pass
    
    def add_edge(self, edge):
        '''
        '''
        pass

    def root(self):
        ''' return root node '''
        pass

def search(graph : IGraph, vertex, visited, parent):
    ''' depth-first search the given graph.'''

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

def has_cycle(graph : IGraph):
    """determine if the graph contains a cycle."""
    visited = { v : False for v in graph.vertices()}

    for vertex in graph.vertices():
        if not visited[vertex]:
            if search(graph, vertex, visited, None):
                return True

    return False


def find_paths(graph : IGraph, start, end, path = None):
    ''' finds a path (if exists) from start -> end'''

    if not path: path = []

    path = path + [start]

    if start == end: 
        return [path]

    paths = []

    for neighbor in graph.neighbors(start):
        if neighbor not in path:
            extended_path = find_paths(graph, neighbor, end, path)

            if extended_path != None:
                paths.append(extended_path)
            
    return paths

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

    def traverse(graph : IGraph, curr, result):
        descendants = 0

        for child in graph.neighbors(curr):
            num_nodes, result = traverse(graph, child, result)

            result[child] += num_nodes - 1
            descendants += num_nodes

        return descendants + 1, result

    start = graph.root()
    vertices = defaultdict(int)

    _, descendants = traverse(graph, start, vertices)

    return len([val for val in descendants.values() if val % 2 == 1])