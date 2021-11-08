import unittest

from dcp.problems.graph.adj_mat_graph import AMGraph
from .graphs import graph_1, graph_2, graph_3

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
