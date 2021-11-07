import unittest

from problems.illuminated import Graph
from problems.illuminated import kargerMinCut

class Test_Karger(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_4_node(self):

        g = {
            1 : [2, 3],
            2 : [1, 3, 4],
            3 : [1, 2, 4],
            4 : [3, 2]
        }

        graph = Graph.from_dict(g)

        from random import seed
        seed(282)

        # default = 2*edges
        minCuts = 2* len(graph.edges())

        for i in range(5):
            result = kargerMinCut( graph )

            minCuts = min(minCuts, result)

        assert minCuts == 2