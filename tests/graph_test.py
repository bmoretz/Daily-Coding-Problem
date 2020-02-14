import unittest

from problems.graph.adj_list_graph import ALGraph
from problems.graph.adj_mat_graph import AMGraph
from problems.graph import max_edges1
from problems.graph import word_ladder1

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


"""
      1
    /   \
   2     3
        /  \
        4    5
    / | \
   6  7  8
"""

graph_4 = {
    1 : [2, 3],
    2 : [],
    3 : [4, 5],
    4 : [6, 7, 8],
    5 : [],
    6 : [],
    7 : [],
    8 : [],
}


class Test_AdjListGraphTests(unittest.TestCase):
    
    def setUp(self):
        self.graph1 = ALGraph(graph_1)
        self.graph2 = ALGraph(graph_2)
        self.graph3 = ALGraph(graph_3)

    def test_case1(self):       
        assert self.graph1.vertices() == ['a', 'b', 'c', 'd', 'e', 'f']

    def test_case2(self):
        
        assert self.graph1.edges() == [{'c', 'a'}, {'c', 'b'}, {'e', 'b'}, {'c', 'a'}, {'c', 'b'}, {'c', 'd'}, {'e', 'c'}, {'c', 'd'}, {'e', 'c'}, {'e', 'b'}]


class Test_AdjListGraphAddTeest(unittest.TestCase):

    def setUp(self):
        self.graph = ALGraph(graph_1)

    def test_case1(self):

        assert self.graph.vertices() == ['a', 'b', 'c', 'd', 'e', 'f']

        self.graph.add_vertex('g')

        assert self.graph.vertices() == ['a', 'b', 'c', 'd', 'e', 'f', 'g']

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


class Test_MaxEdgesAL(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        graph = ALGraph(graph_4)

        assert max_edges1(graph) == 2

class Test_WordLadderAM(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        start, end = "dog", "cat"
        words = {"dot", "dop", "dat", "cat"}

        ladder = word_ladder1(start, end, words)

        assert ladder == ['dog', 'dop', 'dot', 'dat', 'cat']