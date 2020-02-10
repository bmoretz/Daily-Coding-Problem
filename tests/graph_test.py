import unittest

from problems.graph.adj_list_graph import ALGraph
from problems.graph.adj_mat_graph import AMGraph

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

"""
a       b
| \     |  \
|   c   |    f
|     \ |
d       e
"""

graph_3 = { 
    "a" : ["c", "d"],
    "b" : ["e", "f"],
    "c" : ["a", "e"],
    "d" : ["a"],
    "e" : ["c", "b"],
    "f" : ["b"]
}

class Test_AdjListGraphTests(unittest.TestCase):
    
    def setUp(self):
        self.graph1 = ALGraph(graph_1)
        self.graph2 = ALGraph(graph_2)
        self.graph3 = ALGraph(graph_3)

    def test_case1(self):       
        assert self.graph1.vertices() == ['a', 'b', 'c', 'd', 'e', 'f']
        assert self.graph2.vertices() == ['a', 'b', 'c', 'd', 'e', 'f']
        assert self.graph3.vertices() == ['a', 'b', 'c', 'd', 'e', 'f']

    def test_case2(self):
        assert self.graph1.edges() == [{'a', 'c'}, {'b', 'c'}, {'b', 'e'}, {'a', 'c'}, {'b', 'c'}, {'d', 'c'}, {'e', 'c'}, {'d', 'c'}, {'e', 'c'}, {'b', 'e'}]

class Test_AdjMatrixGraphTests(unittest.TestCase):
    
    def setUp(self):
        self.graph1 = AMGraph(graph_1)
        self.graph2 = AMGraph(graph_2)
        self.graph3 = AMGraph(graph_3)

    def test_case1(self):

        assert self.graph1.vertices() == ['a', 'b', 'c', 'd', 'e', 'f']
        assert self.graph2.vertices() == ['a', 'b', 'c', 'd', 'e', 'f']
        assert self.graph3.vertices() == ['a', 'b', 'c', 'd', 'e', 'f']

    def test_case2(self):

        assert self.graph1.edges() == [{'a': 'c'}, {'b': 'c'}, {'b': 'e'}, {'c': 'a'}, {'c': 'b'}, {'c': 'd'}, {'c': 'e'}, {'d': 'c'}, {'e': 'b'}, {'e': 'c'}]