import unittest

from problems.illuminated import read_weighted_graph
from problems.illuminated import shortest_path_fast, shortest_path_slow

from .utility import get_test_file

class Test_Dijkstra(unittest.TestCase):

    def setUp(self):
        self.test_file_path = get_test_file('dijkstra', 'problem9.8test.txt')

    def test_fast(self):

        g = read_weighted_graph(self.test_file_path)

        actual = shortest_path_fast(g, 1)
        expected = {2: 1, 3: 2, 4: 3, 5: 4, 6: 4, 7: 3, 8: 2}

        assert actual == expected

    def test_slow(self):

        g = read_weighted_graph(self.test_file_path)

        actual = shortest_path_slow(g, 1)
        expected = {2: 1, 3: 2, 4: 3, 5: 4, 6: 4, 7: 3, 8: 2}

        assert actual == expected