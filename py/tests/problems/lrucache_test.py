from py.data_structures.LRUCache import LRUCache

import unittest

class Test_LRUCacheBase(unittest.TestCase):
    
    def setUp(self):
        self.cache = LRUCache(5)
        
        items = [(1, 'A'), (2, 'B'), (5, 'E'), (4, 'D'), (3, 'C')] # fill the cache

        for item in items:
            self.cache.insert(item[0], item[1])

    def test_none(self):
    
        actual = self.cache.get(8)
        expected = None

        assert actual == expected

    def test_case1(self):
    
        actual = self.cache.get(1)
        expected = 'A'

        assert actual == expected

    def test_case2(self):
        
        actual = self.cache.get(5)
        expected = 'E'

        assert actual == expected

    def test_case4(self):
        
        actual = self.cache.get(3)
        expected = 'C'

        assert actual == expected

    def test_case5(self):
        
        actual = self.cache.get(4)
        expected = 'D'

        assert actual == expected

class Test_LRUCacheBehavior(unittest.TestCase):

    def test_invalidate_top(self):
        
        cache = LRUCache(5)
        
        items = [(1, 'A'), (2, 'B'), (5, 'E'), (4, 'D'), (3, 'C')] # fill the cache

        for item in items:
            cache.insert(item[0], item[1])

        assert cache.get(1) == 'A'
        assert cache.get(2) == 'B'
        assert cache.get(3) == 'C'
        assert cache.get(4) == 'D'
        assert cache.get(5) == 'E'

        cache.insert(6, 'F')

        assert cache.get(1) == None

        assert cache.get(2) == 'B'
        assert cache.get(3) == 'C'
        assert cache.get(4) == 'D'
        assert cache.get(5) == 'E'
        assert cache.get(6) == 'F'

        assert len(cache) == 5