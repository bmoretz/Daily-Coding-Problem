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