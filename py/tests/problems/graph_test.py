import unittest

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

'''
A ---------> B
  \             \
    \ 
       C            \
    /     \
D --------> F ------> G
    \       |            \
       E    |             H
          \ |
            I
'''

graph_5 = {
    'A' : ['B', 'C'],
    'B' : ['G'],
    'C' : ['F'],
    'D' : ['C', 'F', 'E'],
    'E' : ['I'],
    'F' : ['I'],
    'G' : ['H'],
    'H' : [],
    'I' : []
}

from py.problems.graph.adj_list_graph import ALGraph
class Test_AdjListGraphTests(unittest.TestCase):
    
    def setUp(self):
        self.graph1 = ALGraph(graph_1)
        self.graph2 = ALGraph(graph_2)
        self.graph3 = ALGraph(graph_3)

    def test_case1(self):       
        assert self.graph1.vertices() == ['a', 'b', 'c', 'd', 'e', 'f']

    def test_case2(self):
        
        assert self.graph1.edges() == [{'c', 'a'}, {'c', 'b'}, {'e', 'b'}, {'c', 'a'}, {'c', 'b'}, {'c', 'd'}, {'e', 'c'}, {'c', 'd'}, {'e', 'c'}, {'e', 'b'}]

class Test_AdjListGraphAddTest(unittest.TestCase):

    def setUp(self):
        self.graph = ALGraph(graph_1)

    def test_case1(self):

        assert self.graph.vertices() == ['a', 'b', 'c', 'd', 'e', 'f']

        self.graph.add_vertex('g')

        assert self.graph.vertices() == ['a', 'b', 'c', 'd', 'e', 'f', 'g']

from py.problems.graph.adj_mat_graph import AMGraph
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

from py.problems.graph import max_edges1
class Test_MaxEdgesAL(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        graph = ALGraph(graph_4)

        assert max_edges1(graph) == 2

from py.problems.graph import word_ladder1
class Test_WordLadderAM(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        start, end = "dog", "cat"
        words = {"dot", "dop", "dat", "cat"}

        ladder = word_ladder1(start, end, words)
        exists = True

        assert exists == True

from py.problems.graph import minimum_turns1
class Test_SnakesLadders1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        snakes = {17 : 13, 52 : 29, 57 : 40, 62 : 22, 88 : 18, 95 : 51, 97 : 79}
        ladders = {3 : 21, 8 : 30, 28 : 84, 58 : 77, 75 : 86, 80 : 100, 90 : 91}

        n_squares = 100

        assert minimum_turns1(snakes, ladders, n_squares)

from py.problems.graph import find_order1
class Test_TopologicalSort1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        courses = {
            'CSC300' : ['CSC100', 'CSC200'],
            'CSC200' : ['CSC100'],
            'CSC100' : []
        }        

        assert find_order1(courses) == ['CSC100', 'CSC200', 'CSC300']

from py.problems.graph import has_route1
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

from py.problems.graph import Builder1
class Test_Builder1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        
        builder = Builder1(None, None)

        assert builder != None
        assert builder.build_all() == None

    def test_case2(self):

        projects = ['a', 'b', 'c', 'd', 'e', 'f']
        dependencies = [('a', 'd'), ('f', 'b'), ('b', 'd'), ('f', 'a'), ('d', 'c')]

        builder = Builder1(projects, dependencies)

        success = None

        try:

            build_list = builder.build_all()
                            
            # test build all projects
            for built in build_list:
                projects.remove(built)
            
            success = True

        except Builder1.CircularReferenceError:
            success = False
        
        assert success == True
        assert projects == []

    def test_case3(self):

        # circular build defintion

        projects = ['a', 'b', 'c', 'd', 'e', 'f']
        dependencies = [('a', 'd'), ('f', 'b'), ('b', 'd'), ('f', 'a'), ('d', 'c'), ('c', 'f')]

        builder = Builder1(projects, dependencies)

        success = None

        try:
            # test build all projects
            build_list = builder.build_all()

            for built in build_list:
                projects.remove(built)
            
            success = True
        except Builder1.CircularReferenceError:
            success = False

        assert success == False

    def test_case4(self):

        # circular build defintion

        projects = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
        dependencies = [('a', 'd'), ('f', 'b'), ('b', 'd'), ('f', 'a'), ('d', 'c'), ('c', 'f'), ('b', 'g')]

        builder = Builder1(projects, dependencies)

        success = None

        try:
            build_list = builder.build_all()

            # test build all projects
            for built in build_list:
                projects.remove(built)

            success = True
        except Builder1.CircularReferenceError:
            success = False

        assert success == False

    def test_case5(self):

        # circular build defintion

        projects = ['a', 'b', 'c', 'd', 'e', 'f', 'h']
        dependencies = [('a', 'e'), ('b', 'a'), ('c', 'a'), ('f', 'a'), ('f', 'c'), ('f', 'b'), ('b', 'e'), ('d', 'g'), ('b', 'h'), ['e', 'f']]

        builder = Builder1(projects, dependencies)

        success = False
        # test build all projects
        try:
            
            build_list = builder.build_all()

            for built in build_list:
                projects.remove(built)

            success = True
        
        except Builder1.CircularReferenceError:
            success = False
        
        assert success == False
        assert projects != []

    def test_case5(self):

        # non-circular build defintion

        projects = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
        dependencies = [('a', 'e'), ('b', 'a'), ('c', 'a'), ('f', 'a'), ('f', 'c'), ('f', 'b'), ('b', 'e'), ('d', 'g')]

        builder = Builder1(projects, dependencies)

        success = False
        # test build all projects
        try:
            
            build_list = builder.build_all()

            for built in build_list:
                projects.remove(built)

            success = True
        
        except Builder1.CircularReferenceError:
            success = False
        
        assert success == True
        assert projects == []

from collections import defaultdict
from py.problems.graph import BabyNames
class Test_BabyNames(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        bn = BabyNames()

        actual = bn.get_unique()
        expected = defaultdict(int)

        assert actual == expected

    def test_case1(self):
        
        bn = BabyNames()

        names = [('John', 15), ('Jon', 12), ('Chris', 13), ('Kris', 4), ('Christopher', 19)]
        synonyms = [('John', 'Jon'), ('John', 'Johnny'), ('Chris', 'Kris'), ('Chris', 'Christopher')]

        for name, count in names:
            bn.add_name(name, count)

        for a, b in synonyms:
            bn.add_synonym(a, b)

        actual = bn.get_unique()
        expected = { "John": 27, "Chris" : 36}

        assert actual == expected

    def test_case2(self):
        
        bn = BabyNames()

        names = [('John', 15), ('Jon', 12), ('Chris', 13), ('Kris', 4), ('Christopher', 19), ('Johnny', 7)]
        synonyms = [('John', 'Jon'), ('John', 'Johnny'), ('Chris', 'Kris'), ('Chris', 'Christopher')]

        for name, count in names:
            bn.add_name(name, count)

        for a, b in synonyms:
            bn.add_synonym(a, b)

        actual = bn.get_unique()
        expected = { "John": 34, "Chris" : 36}

        assert actual == expected

    def test_case2(self):
        
        bn = BabyNames()

        names = [('John', 15), ('Jon', 12), ('Chris', 13), ('Kris', 4), ('Christopher', 19), ('Johnny', 7), ('Jimmy', 5)]
        synonyms = [('John', 'Jon'), ('John', 'Johnny'), ('Chris', 'Kris'), ('Chris', 'Christopher'), ('Jimmy', 'John')]

        for name, count in names:
            bn.add_name(name, count)

        for a, b in synonyms:
            bn.add_synonym(a, b)

        actual = bn.get_unique()
        expected = { "John": 39, "Chris" : 36}

        assert actual == expected

    def test_case3(self):
        
        bn = BabyNames()

        names = [('John', 15), ('Jon', 12), ('Chris', 13), ('Kris', 4), ('Christopher', 19), ('Johnny', 7), ('Bryan', 10), ('Brian', 15)]
        synonyms = [('John', 'Jon'), ('John', 'Johnny'), ('Chris', 'Kris'), ('Chris', 'Christopher')]

        for name, count in names:
            bn.add_name(name, count)

        for a, b in synonyms:
            bn.add_synonym(a, b)

        actual = bn.get_unique()
        expected = { "John": 34, "Chris" : 36, "Brian" : 15, "Bryan" : 10 }

        assert actual == expected

    def test_case4(self):
        
        bn = BabyNames()

        names = [('John', 15), ('Jon', 12), ('Chris', 13), ('Kris', 4), ('Christopher', 19), ('Johnny', 7), ('Bryan', 10), ('Brian', 15)]
        synonyms = [('John', 'Jon'), ('John', 'Johnny'), ('Chris', 'Kris'), ('Chris', 'Christopher'), ('Brian', 'Bryan')]

        for name, count in names:
            bn.add_name(name, count)

        for a, b in synonyms:
            bn.add_synonym(a, b)

        actual = bn.get_unique()
        expected = { "John": 34, "Chris" : 36, 'Bryan' : 25 }

        assert actual == expected

    def test_case5(self):
        
        bn = BabyNames()

        names = [('John', 15), ('Jon', 12), ('Chris', 13), ('Kris', 4), ('Christopher', 19), ('Johnny', 7), ('Bryan', 10), ('Brian', 15), ('BMoney', 6)]
        synonyms = [('John', 'Jon'), ('John', 'Johnny'), ('Chris', 'Kris'), ('Chris', 'Christopher'), ('Brian', 'Bryan'), ('Bryan', 'BMoney')]

        for name, count in names:
            bn.add_name(name, count)

        for a, b in synonyms:
            bn.add_synonym(a, b)

        actual = bn.get_unique()
        expected = { "John": 34, "Chris" : 36, 'Bryan' : 31 }

        assert actual == expected