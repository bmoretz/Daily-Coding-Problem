'''LRU Cache.

Design and build a "least recently used" cache, which evicts the
least recently used item. The cache should map from keys to values
(allowing you to insert and retrieve a value associated with a 
particular key) and be initialized with a max size. When it is full,
it should evict the least recently used item.
'''

class LRUCache():

    '''
    Key list is a doubly-linked list that supports two key
    operations:
        push front
        pop back

    keys will be inserted at the front through the push
    front operation which is O(1). When we reach the max
    key length (k), we simply remove the last element in
    the list through the pop_back, which again is O(1).
    '''
    class KeyList():
        
        class Node():
            def __init__(self, data, prev=None, nxt=None):
                self.data = data
                self.next = nxt
                self.prev = prev

            def _unlink(self):
                
                if self.prev:
                    self.prev.next = self.next
                
                if self.next:
                    self.next.prev = self.prev

        def __init__(self):
            self.head = self.Node(None)
            self.tail = self.Node(None, prev=self.head)
            self.head.next, self.head.prev = self.tail, self.tail
            self.length = 0

        def front(self):
            return self.head.next.data

        '''
        insert item into the list at the front.
        O(1)
        '''
        def push_front(self, value):
            
            new_node = self.Node(data=value, \
                prev=self.head, nxt=self.head.next)

            self.head.next.prev = new_node
            self.head.next = new_node

            self.length += 1

        '''
        remove item from the list from the back.
        O(1)
        '''
        def pop_back(self):
            
            value = self.tail.prev.data

            self.tail.prev._unlink()
            self.length -= 1

            return value
        
        '''
        remove item from the list, regardless of position.
        O(K)
        '''
        def remove(self, value):
            node, prev = self.head, None
            
            while node:
                if node.data == value:
                    node._unlink()
                    self.length -= 1
                    break
                node = node.next

        def __len__(self):
            return self.length

    def __init__(self, k):
        self._data = {}
        self._keys = self.KeyList()
        self._max = k

    '''
    insert item into the cache

    if the key already exists (we leverage the existing hash table for the key
    value pairs which is O(1), then we remove it (O(K))). This will help ensure
    that the invariant of the latest item accessed (via inserted/retrieved) is
    at the front of the list.

    if we're at capacity of the cache, just remove the tail of the key list
    and then delete that item from the hash table of k/v pairs.

    lastly, push the key into the front of the key list and set the value
    of the key in the data items hash table.
    '''
    def insert(self, key, value):
        
        if key in self._data:
            self._keys.remove(key)
        elif len(self._keys) == self._max:
            to_rem = self._keys.pop_back()
            del self._data[to_rem]

        self._keys.push_front(key)
        self._data[key] = value

    '''
    if we have the key in the cache, remove it, then re-insert it
    at the front of the key list and return the corresponding value
    from the items hash table.
    '''
    def get(self, key):

        if key in self._data:
            if self._keys.front() != key:
                self._keys.remove(key)
                self._keys.push_front(key)

            return self._data[key]
        
        return None

    def __str__(self):
        return ', '.join([str(item) for item in self._data])

    def __len__(self):
        return len(self._data)