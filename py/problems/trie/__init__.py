from collections import defaultdict

ENDS_HERE = '#'

class Trie:
    def __init__(self):
        self._trie = {}

    def insert(self, text):
        trie = self._trie

        for char in text:
            if char not in trie:
                trie[char] = {}
            trie = trie[char]
        trie[ENDS_HERE] = True

    def find(self, prefix):
        trie = self._trie
        for char in prefix:
            if char in trie:
                trie = trie[char]
            else:
                return None
        return trie
    
    def _elements(self, d):
        result = []

        for key, value in d.items():
            if key == ENDS_HERE:
                subresult = ['']
            else:
                subresult = [key + suffix for suffix in self._elements(value)]
            result.extend(subresult)

        return result

'''Implement an autocomplete system. 

That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].
'''
class Autocomplete1():

    def __init__(self):
        self._words = Trie()

    def insert_words(self, values):

        for val in values:
            self._words.insert(val)
                
    def get_matches(self, prefix):

        matches = self._words.find(prefix)

        suffix = self._words._elements(matches)

        return [prefix + word for word in suffix]

class Autocomplete2():

    def __init__(self):
        self.words = set()

    def insert_words(self, words):
        
        for word in words:
            self.words.add(word)

    def get_matches(self, prefix):

        results = []
        for word in self.words:
            if word.startswith(prefix):
                results.append(word)

        return results

class Autocomplete3:

    def __init__(self):
        self.words = {}

    def insert(self, word : str):
        
        level = self.words

        for char in word:
            if char not in level: 
                level[char] = {}
            level = level[char]
        level[ENDS_HERE] = '#'

    def expand(self, values : dict):

        results = []

        for key, value in values.items():

            if key == ENDS_HERE:
                subresult = ['']
            else:
                subresult = [key + suffix for suffix in self.expand(value)]
            
            results.extend(subresult)

        return results

    def find(self, prefix : str):

        level = self.words

        for char in prefix:
            if char in level:
                level = level[char]

        return [prefix + word for word in self.expand(level)]

''' Create Prefix Map Sum.

Implement a PrefixMapSum class with the following methods:

insert(key: str, value: int): Set a given key's value in the map. If the key already exists, overwrite the value.

sum(prefix: str): Return the sum of all values of keys that begin with a given prefix.

For example,

you should be able to run the following code:

mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5
'''

class PrefixMapSum1():

    def __init__(self):
        self._map = {}

    '''O(1)'''
    def insert(self, key : str, value : int):
        self._map[key] = value

    '''O(N * K)'''
    def sum(self, prefix : str):
        return sum( value for key, value in self._map.items()
            if key.startswith(prefix))


class PrefixMapSum2():

    def __init__(self):
        self._map = defaultdict(int)
        self._words = set()

    '''O(k^2)'''
    def insert(self, key : str, value : int):
        # if the key already exists, increment prefix totals
        # by the difference of old and new values
        if key in self._words:
            value -= self._map[key]
        self._words.add(key)
    
        for index in range(1, len(key) + 1):
            self._map[key[:index]] += value

    '''O(1)'''
    def sum(self, stri):
        return self._map[stri]

'''Maximum XOR.

Find the maximum XOR of element pairs.

Given an array of integers, find the maximum XOR of any two elements.
'''

class MaxXOR1:

    def __init__(self, values):
        self._trie = {}
        self.size = 0

        for val in values:
            self.size = max(self.size, val.bit_length())

        for val in values: self.insert(val)

    def insert(self, item):
        
        trie = self._trie

        for index in range(self.size, -1, -1):
            bit = bool(item & (1 << index))
            
            if bit not in trie:
                trie[bit] = {}
            
            trie = trie[bit]

    def find_max_xor(self, item):
        trie = self._trie
        xor = 0

        for index in range(self.size, -1, -1):
            bit = bool(item & (1 << index))

            if (1 - bit) in trie:
                xor |= (1 << index)
                trie = trie[1 - bit]
            else:
                trie = trie[bit]

        return xor