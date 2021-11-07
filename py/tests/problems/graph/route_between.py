import unittest

from dcp.problems.graph.route_between import has_route1
from graphs import graph_5

class Test_HasRoute1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert has_route1(None, 'A', 'K') == None

    def test_case2(self):
        assert has_route1(graph_5, 'K', 'A') == False
        assert has_route1(graph_5, 'A', 'K') == False

    def test_case3(self):
        assert has_route1(graph_5, 'A', 'I') == True

    def test_case4(self):
        assert has_route1(graph_5, 'A', 'G') == True

    def test_case5(self):
        assert has_route1(graph_5, 'A', 'D') == False

    def test_case6(self):
        assert has_route1(graph_5, 'C', 'I') == True
    
    def test_case7(self):
        assert has_route1(graph_5, 'C', 'H') == False