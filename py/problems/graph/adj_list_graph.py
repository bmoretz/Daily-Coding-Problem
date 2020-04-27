from collections import defaultdict

from abc import ABCMeta 

from py.problems.graph import IGraph, InvalidState

class ALGraph(metaclass=ABCMeta):
    """Adjacency list graph implementation."""

    def __init__(self, graph_dict=None):

        """ initialize a graph object
            If no dictionary is given,
            an empty one will be used."""

        if graph_dict == None:
            graph_dict = {}
        
        self.__graph_dict = graph_dict.copy()

    def vertices(self):
        return list(self.__graph_dict.keys())

    def edges(self):
        return self.__generate_edges()

    def isolated(self):
        
        isolated = []

        for node in self.__graph_dict:
            if not self.__graph_dict[node]:
                isolated += node

        return isolated

    def neighbors(self, vertex):

        if vertex not in self.__graph_dict: raise InvalidState

        return self.__graph_dict[vertex]

    def add_vertex(self, vertex):
        """ If the vertex "vertex" is not in
        self.__graph_dict, a key "vertex" with an empty
        list as a value is added to the dictionary.
        """

        if vertex not in self.__graph_dict:
            self.__graph_dict[vertex] = []

    def add_edge(self, edge):
        """ assumes that edge is of type set, tuple or list;
            between two vertices can be multiple edges.
        """

        edge = set(edge)
        (vertex1, vertex2) = tuple(edge)
        if vertex1 in self.__graph_dict:
            self.__graph_dict[vertex1].append(vertex2)
        else:
            self.__graph_dict[vertex1] = [vertex2]
    
    def __generate_edges(self):
        """ A static method generating the edges of the 
        graph. Edges are represented as sets with one,
        a loop back to the vertex, or two vertices.
        """
        
        edges = []
        for vertex in self.__graph_dict:
            for neighbor in self.__graph_dict[vertex]:
                if (neighbor, vertex) not in edges:
                    edges.append({vertex, neighbor})
        return edges
            
    def root(self):
        
        if len(self.__graph_dict) == 0:
            raise InvalidState('Empty Graph')

        return list(self.__graph_dict)[0]
        
    def __str__(self):
        res = "vertices: "
        for k in self.__graph_dict:
            res += str(k) + " "
        res += "\nedges: "
        for edge in self.__generate_edges():
            res += str(edge) + " "
        return res