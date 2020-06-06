from py.data_structures import LRUCache

import unittest

class Test_LRUCache(unittest.TestCase):
    
    def setUp(self):
        self.cache = LRUCache()
        
        items = [(1, 'A'), (2, 'B'), (5, 'E'), (4, 'D'), (3, 'C')] # fill the cache

        for item in items:
            cache.insert(item[0], item[1])

    def case_none(self):
    
        actual = cache.get(8)
        expected = None

        assert actual == expected