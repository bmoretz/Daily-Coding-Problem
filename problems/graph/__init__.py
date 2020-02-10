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

    def search(self, vertex, visited, parent):
        """Search the graph. """
        pass

    def has_cycle(self):
        """ static method to determine if the graph contains a cylce. """