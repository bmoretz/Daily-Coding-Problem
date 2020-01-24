
from collections import defaultdict

'''5.3

Implement a sparse array.

You have a large array, most of whose elements are zero.

Create a more space-efficient data structure, SparseArray, that implements the following interface:

+ init(arr, size): initialize with the original large array and size.

+ set(i, val): update index at i to be val.

+ get(i): get the value at index i.

'''

arr = [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1]

class SparseArray:

    def __init__(self, arr, size):
        self._values = defaultdict()
        self._size = size

        for pos, value in enumerate(arr):
            if value != 0:
                self._values[pos] = value

    def _check_bounds(self, pos):
        if pos < 0 or pos >= self._size:
            raise IndexError('Out of bounds')

    def set(self, index, value):

        self._check_bounds(index)

        if value != 0:
            self._values[index] = value
            return
        elif index in self._values:
            del self._values[index]

    def get(self, index):
        
        self._check_bounds(index)

        return self._values.get(index, 0)


sa = SparseArray(arr, 100)

non_zero = [5, 13, 19, 28]

for index in range(len(arr)):

    if index in non_zero:
        assert sa.get(index) != 0
    else:
        assert sa.get(index) == 0

from problems.hashtable import LRUCache

cache = LRUCache(5)

for index in range(10):
    cache.set(index, index**2)

k = list( cache.dict.keys() )

print(k)