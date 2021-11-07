import unittest

from problems.illuminated import read_cost_graph_data
from problems.illuminated import prim_slow, prim_fast

from .utility import get_test_file

class Test_PrimsMST(unittest.TestCase):

    def setUp(self):

        self.test_file_path = get_test_file('prim-mst', 'problem15.9test.txt')

    def test_fast(self):

        graph = read_cost_graph_data(self.test_file_path)

        actual = prim_slow(graph)
        expected = 14

        assert actual == expected

    def test_slow(self):

        graph = read_cost_graph_data(self.test_file_path)

        actual = prim_fast(graph)
        expected = 14

        assert actual == expected