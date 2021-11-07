import unittest

from collections import defaultdict
from dcp.problems.graph.baby_names import BabyNames

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