from collections import defaultdict

'''Two Sum.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given

[10, 15, 3, 7] and k = 17,

we should return True, since 10 + 7 = 17
'''

def two_sum1(lst, k):

    seen = {}

    for num in lst:
        if k - num in seen:
            return True

        seen[num] = True

    return False

'''LRU Cache.

Implement a LRU (Least Recently Used) cache. The cache should be able to be initialized with cache size n, and provide the following methods:

1.) set(key, value): set key to value. If there are already n items in the cache and we are adding a new item, also remove the least recently used item.

2.) get(key): get the value at key. If no such key exists, return null.

Each operation should run in O(1) time.
'''

class Node:

    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

class LinkedList:

    def __init__(self):
        self.head = Node(None, 'head')
        self.tail = Node(None, 'tail')

        self.head.next = self.tail
        self.tail.prev = self.head

    def get_head(self):
        return self.head.next

    def get_tail(self):
        return self.tail.prev

    def add(self, node):
        prev = self.tail.prev
        prev.next = node
        node.prev = prev
        node.next = self.tail
        self.tail.prev = node

    def remove(self, node):
        prev = node.prev
        nxt = node.next
        prev.next = nxt
        nxt.prev = prev

class LRUCache():
    
    def __init__(self, n):
        self.n = n
        self.dict = {}
        self.list = LinkedList()

    def set(self, key, value):
        if key in self.dict:
            self.dict[key].delete()

        n = Node(key, value)
        self.list.add(n)
        self.dict[key] = n

        if len(self.dict) > self.n:
            head = self.list.get_head()
            self.list.remove(head)
            del self.dict[head.key]

    def get(self, key, value):
        if key in self.dict:
            n = self.dict[key]

            # Bump to the back of the list by removing and adding the node
            self.list.remove(n)
            self.list.add(n)

            return n.val

'''Cut Brick Wall.

A wall consists of several rows of bricks and various integer lengths and uniform height. 

Your goal is to find a vertical line going from the top to the bottom of the wall that cuts through the fewest number of bricks.

If the line goes through the edge between two bricks, this does not count as a cut.

For example, suppose the input is as follows, where values in each row represent the lengths of bricks in that row:

[[3, 5, 1, 1],
[2, 3, 3, 2],
[5, 5],
[4, 4, 2],
[1, 3, 3, 3],
[1, 1, 6, 1, 1]]

The best we can do here is draw a line after the eighth brick, which will only require cutting through the bricks in the third and fifth row.

Given an input consisting of brick lengths for each row such as the one above, return the fewest number of bricks that must be cut to create a vertical line.
'''

def fewest_cuts1(wall):

    cuts = defaultdict(int)

    for row in wall:
        length = 0
        for brick in row[:-1]:
            length += brick
            cuts[length] += 1

    return len(wall) - max(cuts.values())

'''Implement a sparse array.

You have a large array, most of whose elements are zero.

Create a more space-efficient data structure, SparseArray, that implements the following interface:

+ init(arr, size): initialize with the original large array and size.

+ set(i, val): update index at i to be val.

+ get(i): get the value at index i.

'''

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

'''Implement a sparse matrix.

You have a large n by m array of data, most of whose elements are zero.

Create a more space-efficient data structure, SparseMatrix, that implements the following interface:

+ init(mat, width, height): initialize with the original large n by m array and size.

+ set(row, col, val): update index at [row, col] to be val.

+ get(row, col): get the value at index [row, col].

'''

rec_dd = lambda: defaultdict(rec_dd) # recursive defaultdict for sparse matrix

class SparseMatrix:
    '''O(n * m) initialize'''
    def __init__(self, mat, width, height):
        self._values = rec_dd()
        self._n, self._m = width, height

        for n, row in enumerate(mat):
            for m, val in enumerate(row):
                if val != 0:
                    self._values[n][m] = val

    '''O(1) check bounds'''
    def _check_bounds(self, n, m):
        if n < 0 or n >= self._n or m < 0 or m >= self._m:
            raise IndexError('Out of bounds')

    '''O(1) set val'''
    def set(self, row, col, value):

        self._check_bounds(row, col)

        if value != 0:
            self._values[row][col] = value
            return
        elif col in self._values[row]:
            del self._values[row][col]

    '''O(1) get val'''
    def get(self, row, col):
        
        self._check_bounds(row, col)

        return self._values.get(row, []).get(col, 0)

'''Word Frequencies.

Design a method to find the frequency of occurrences of any given word
in a book. What if we were running this algorithm multiple times?
'''

from collections import defaultdict
from string import ascii_letters

def word_frequency(text):

    if text == None: return None

    cleaned = ''

    for char in text:     
        if char == ' ' or char in ascii_letters:
            cleaned += char

    words = cleaned.lower().split(' ')

    freq = defaultdict(int)    

    for word in words:
        freq[word] += 1

    return freq

'''Paris with Sum.

Design an algorithm to find all pairs of integers within an array which sum
to a specified value.
'''

'''
O(n) solution
'''
def pair_sum(arr, t):
    
    if not arr: return None

    lookup = defaultdict(int)

    for n in arr:
        lookup[n] += 1

    results = set()

    for index, x in enumerate(arr):
        y = t - x

        # can't sum it with itself to find a pair,
        # there needs to be at least 2 of the same
        # number if this is the case.
        if y == x and lookup[x] == 1:
            continue

        if y in lookup and (y, x) not in results:
            results.add((x, y))

    return results