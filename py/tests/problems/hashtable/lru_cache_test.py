import unittest

from dcp.problems.hashtable.lru_cache import LRUCache

class Test_LRUCache(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        cache = LRUCache(5)

        for index in range(10):
            cache.set(index, index**2)

        assert list(cache.dict.keys()) == [5, 6, 7, 8, 9]