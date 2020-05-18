import unittest

from py.problems.illuminated import karatsuba
class Test_Karatsuba(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        x, y = 45, 76

        actual = karatsuba(x, y)
        expected = 3420

        assert actual == expected

    def test_case2(self):

        x, y = 4898, 3988

        actual = karatsuba(x, y)
        expected = 19533224

        assert actual == expected

    def test_case3(self):

        x, y = 1465, 1275

        actual = karatsuba(x, y)
        expected = 1867875

        assert actual == expected

    def test_case4(self):

        x, y = 146, 127

        actual = karatsuba(x, y)

        expected = 18542

        assert actual == expected

    def test_case5(self):

        x = 3141592653589793238462643383279502884197169399375105820974944592
        y = 2718281828459045235360287471352662497757247093699959574966967627

        actual = karatsuba(x, y)

        expected = 8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184

        assert actual == expected

from py.problems.illuminated import count_inversions
class Test_CountInversions(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        arr = [1, 3, 5, 2, 4, 6]

        actual = count_inversions(arr)
        expected = 3

        assert actual == expected

    def test_case2(self):

        arr = [1, 3, 5, 2, 4, 6, 4]

        actual = count_inversions(arr)
        expected = 5

        assert actual == expected

    def test_case3(self):

        arr = [1, 5, 3, 2, 4, 6]

        actual = count_inversions(arr)
        expected = 4

        assert actual == expected

    def test_case4(self):

        arr = [1, 5, 3, 2, 1]

        actual = count_inversions(arr)
        expected = 6

        assert actual == expected

    def test_case4(self):

        arr = [1, 3]

        actual = count_inversions(arr)
        expected = 0

        assert actual == expected

from py.problems.illuminated import quick_sort
from py.problems.illuminated import pivot_0, pivot_n, pivot_m
from py.problems.illuminated import get_sort_data

class Test_QuickSort(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_pivot_0(self):

        arr = get_sort_data()

        quick_sort(arr, choose_pivot=pivot_0)
        
        assert arr == sorted(arr)

    def test_pivot_n(self):

        arr = get_sort_data()

        quick_sort(arr, choose_pivot=pivot_n)
        
        assert arr == sorted(arr)

    def test_pivot_m(self):

        arr = get_sort_data()

        quick_sort(arr, choose_pivot=pivot_m)
        
        assert arr == sorted(arr)

from py.problems.illuminated import Graph
from py.problems.illuminated import kargerMinCut

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

from py.problems.illuminated import run_kosaraju

class Test_Kosaraju(unittest.TestCase):

    def setUp(self):
        from os import getcwd

        data_dir = data_dir = getcwd() + '\\data\\illuminated\\kosaraju\\'

        cases = {}

        for case in range(1, 7):
            cases[case] = f'{data_dir}problem8.10test' + str(case) + '.txt'
        
        self.test_cases = cases

        self.expected_output = {
            1 : [3, 3, 3, 0, 0],
            2 : [3, 3, 2, 0, 0],
            3 : [3, 3, 1, 1, 0],
            4 : [7, 1, 0, 0, 0],
            5 : [6, 3, 2, 1, 0],
            6 : [3, 1, 1, 0, 0],
        }

    def test_cases_disk(self):

        for case in self.test_cases.items():

            result = run_kosaraju(case[1])

            assert result == self.expected_output[case[0]]


from py.problems.illuminated import WeightedGraph
from py.problems.illuminated import read_weighted_graph
from py.problems.illuminated import shortest_path_fast, shortest_path_slow

class Test_Dijkstra(unittest.TestCase):

    def setUp(self):

        from os import getcwd
        
        data_dir = getcwd() + '\\data\\illuminated\\dijkstra\\'

        self.test_file_path = data_dir + 'problem9.8test.txt'

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