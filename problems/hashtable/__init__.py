from collections import defaultdict

'''5.0

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

'''5.1

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

'''5.2

A wall consists of several rows of bricks and various integer lengths and uniform height. 

Your goal is to find a vertical line going from the top to the bottom of the wall that cuts through the fewest number of bricks.

If the line goes through the edge between two bricks, this does not count as a cut.

For example, suppose the input is as follows, where values in each row represent the lenghts of bricks in that row:

[[3, 5, 1, 1],
[2, 3, 3, 2],
[5, 5],
[4, 4, 2],
[1, 3, 3, 3],
[1, 1, 6, 1, 1]]

The best we can do here is draw a line after the eighth brick, which will only require cutting through the bricks in the thrid  and fifth row.

Given an input consisting of brick lenghts for each row such as the one above, return the fewest number of bricks that must be cut to create a vertical line.
'''

def fewest_cuts1(wall):

    cuts = defaultdict(int)

    for row in wall:
        length = 0
        for brick in row[:-1]:
            length += brick
            cuts[length] += 1

    return len(wall) - max(cuts.values())

'''5.3

Implement a sparse array.

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