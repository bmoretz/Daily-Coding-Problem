
from problems.hashtable import LRUCache

'''5.1

Implement a LRU (Least Recently Used) cache. The cache should be able to be initialized with cache size n, and provide the following methods:

1.) set(key, value): set key to value. If there are already n items in the cache and we are adding a new item, also remove the least recently used item.

2.) get(key): get the value at key. If no such key exists, return null.

Each operation should run in O(1) time.
'''

cache = LRUCache(5)

for index in range(10):
    cache.set(index, index**2)

print(cache.dict.keys())