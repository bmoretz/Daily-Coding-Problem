from abc import ABC

class InvalidState(ValueError):
    '''Exception raised when the state is invalid.'''
    
    def __repr__(self):
        return 'The state of the graph is invalid for this operation.'

class IGraph(ABC):

    def vertices(self):
        ''' returns the vertices of the graph.''' 
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

def find_path(graph : IGraph, start, end, path=[]):
    ''' finds a path (if exists) from start -> end '''

    path = path + [start]

    if start == end:
        return path

    for neighbor in graph.neighbors(start):
        if neighbor not in path:
            newpath = find_path(graph, neighbor, end, path)

            if newpath: return newpath

    return None