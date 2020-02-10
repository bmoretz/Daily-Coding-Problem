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
                if connection:
                    edges.append({index_lookup[col] : index_lookup[index]})

        return edges    

    def neighbors(self, vertex):
        pass

    def add_vertex(self, vertex):
        pass

    def add_edge(self, edge):
        pass

    def search(self, vertex, visited, parent):
        pass

    def has_cycle(self):
        pass