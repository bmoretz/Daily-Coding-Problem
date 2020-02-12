from collections import defaultdict
from interface import implements

from problems.graph import IGraph, InvalidState

class AMGraph(implements(IGraph)):
    """Adjacency matrix graph implementation."""

    def __init__(self, graph_dict=None):
        self._indices = {}
        self._connections = []

        if graph_dict:
            
            self._indices = { key : index for index, key in enumerate(graph_dict.keys())}

            for _, vertex in enumerate(self._indices):
                
                row = [0] * len(graph_dict.keys())

                for connection in graph_dict[vertex]:
                    index = self._indices[connection]
                    row[index] = 1                

                self._connections.append(row)

    def vertices(self):
        return list(self._indices.keys())

    def edges(self):
        
        edges = []

        index_lookup = list(self._indices.keys())

        for col, row in enumerate(self._connections):
            for index, connection in enumerate(row):
                vertex, neighbor = index_lookup[col], index_lookup[index]
                if connection and (neighbor, vertex) not in edges:
                    edges.append({vertex : neighbor})

        return edges    

    def isolated(self):
        
        isolated = []

        for index, row in enumerate(self._connections):
            if sum(row) == 0:
                isolated += self.vertices()[index]

        return isolated


    def neighbors(self, vertex):

        index = self._indices[vertex]
        
        vertices = list(self._indices.keys())

        neighbors = [vertices[index] for index, vertex in enumerate(self._connections[index]) if vertex == 1]

        return neighbors

    def add_vertex(self, vertex):
        
        n = len(self._indices)

        self._indices[vertex] = n
        self._connections.append([0] * n)

    def add_edge(self, edge):
        """ assumes that edge is of type set, tuple or list;
            between two vertices can be multiple edges.
        """

        edge = set(edge)
        (vertex1, vertex2) = tuple(edge)

        index1, index2 = self._indices[vertex1], self._indices[vertex2]

        self._connections[index1][index2] = 1

