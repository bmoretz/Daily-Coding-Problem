import unittest

from problems.trie import Autocomplete1, Autocomplete2

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