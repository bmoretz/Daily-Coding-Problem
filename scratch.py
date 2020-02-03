from problems.trie import Trie

from problems.trie import Autocomplete1

from collections import defaultdict

'''8.2
Create Prefix Map Sum

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


class PrefixMapSum2():

    def __init__(self):
        self._map = defaultdict()
        self._words = set()

    '''O(k^2)'''
    def insert(self, key : str, value : int):
        # if the key already exists, increment prefix totals
        # by the difference of old and new values
        if key in self._words:
            value -= self._map[key]
        self._words.add(key)
    
    '''O(1)'''
    def sum(self, stri):
        return self._map[stri]

    
mapsum = PrefixMapSum2()

mapsum.insert("columar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5

print("")