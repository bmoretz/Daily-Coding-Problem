import unittest

from dcp.problems.graph.adj_list_graph import ALGraph
from .graphs import graph_1, graph_2, graph_3

class Test_AdjListGraphTests(unittest.TestCase):
    
    def setUp(self):
        self.graph1 = ALGraph(graph_1)
        self.graph2 = ALGraph(graph_2)
        self.graph3 = ALGraph(graph_3)

    def test_case1(self):       
        assert self.graph1.vertices() == ['a', 'b', 'c', 'd', 'e', 'f']

    def test_case2(self):
        assert self.graph1.edges() == [{'c', 'a'}, {'c', 'b'}, {'e', 'b'}, {'c', 'a'}, {'c', 'b'}, {'c', 'd'}, {'e', 'c'}, {'c', 'd'}, {'e', 'c'}, {'e', 'b'}]
