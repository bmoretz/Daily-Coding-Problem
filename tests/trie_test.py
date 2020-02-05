import unittest

from problems.trie import Autocomplete1, Autocomplete2
from problems.trie import PrefixMapSum1, PrefixMapSum2
from problems.trie import MaxXOR1

class Test_Autocomplete1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        values, search = ['dog', 'deer', 'deal'], "de"

        ac = Autocomplete1()
        ac.insert_words(values)

        results = ac.get_matches(search)

        assert 'deer' in results
        assert 'deal' in results

class Test_Autocomplete2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        values, search = ['dog', 'deer', 'deal'], "de"

        ac = Autocomplete2()
        ac.insert_words(values)

        results = ac.get_matches(search)

        assert 'deer' in results
        assert 'deal' in results

class Test_Autocomplete3(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        values, search = ['dog', 'deer', 'deal', 'deed'], "de"

        ac = Autocomplete2()
        ac.insert_words(values)

        results = ac.get_matches(search)

        assert 'deer' in results
        assert 'deal' in results
        assert 'deed' in results

class Test_MapSum1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        mapsum = PrefixMapSum1()

        mapsum.insert("columar", 3)
        assert mapsum.sum("col") == 3

        mapsum.insert("column", 2)
        assert mapsum.sum("col") == 5


class Test_MapSum2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        mapsum = PrefixMapSum2()

        mapsum.insert("columar", 3)
        assert mapsum.sum("col") == 3

        mapsum.insert("column", 2)
        assert mapsum.sum("col") == 5


class Test_MaxXOR(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        values = [4, 7, 6]
        mx = MaxXOR1(values)

        assert mx.find_max_xor(2) == 6