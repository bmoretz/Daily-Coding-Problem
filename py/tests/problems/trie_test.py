import unittest

from problems.trie import Autocomplete1
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

from problems.trie import Autocomplete2
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

from problems.trie import PrefixMapSum1
class Test_MapSum1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        mapsum = PrefixMapSum1()

        mapsum.insert("columar", 3)
        assert mapsum.sum("col") == 3

        mapsum.insert("column", 2)
        assert mapsum.sum("col") == 5

from problems.trie import PrefixMapSum2
class Test_MapSum2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        mapsum = PrefixMapSum2()

        mapsum.insert("columar", 3)
        assert mapsum.sum("col") == 3

        mapsum.insert("column", 2)
        assert mapsum.sum("col") == 5

from problems.trie import MaxXOR1
class Test_MaxXOR(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        values = [4, 7, 6]
        mx = MaxXOR1(values)

        assert mx.find_max_xor(2) == 6

from problems.trie import T9
class Test_T9(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_none(self):

        words = ['used', 'tree', 'angry', 'world', 'alpha', 'trip', 'usage', 'triangle']

        calc = T9(word_list=words)

        actual = calc.get_matches(None)
        expected = None

        assert actual == expected

    def test_case1(self):
        
        words = ['used', 'tree', 'angry', 'world', 'alpha', 'trip', 'usage', 'triangle']

        calc = T9(word_list=words)

        actual = calc.get_matches(8733)
        expected = ['used', 'tree']

        assert actual == expected

    def test_case2(self):
        
        words = ['used', 'tree', 'angry', 'world', 'alpha', 'trip', 'usage', 'triangle', 'apple', 'milk']

        calc = T9(word_list=words)

        actual = calc.get_matches(6455)
        expected = ['milk']

        assert actual == expected

    def test_case3(self):
        
        words = ['used', 'tree', 'angry', 'world', 'alpha', 'trip', 'usage', 'triangle', 'apple', 'milk']

        calc = T9(word_list=words)

        actual = calc.get_matches(25742)
        expected = ['alpha']

        assert actual == expected

    def test_case4(self):
        
        words = ['used', 'tree', 'angry', 'world', 'alpha', 'trip', 'usage', 'triangle', 'apple', 'milk']

        calc = T9(word_list=words)

        actual = calc.get_matches(96753)
        expected = ['world']

        assert actual == expected

    def test_case5(self):
        
        words = ['used', 'tree', 'angry', 'world', 'alpha', 'trip', 'usage', 'triangle', 'apple', 'milk']

        calc = T9(word_list=words)

        actual = calc.get_matches(26479)
        expected = ['angry']

        assert actual == expected