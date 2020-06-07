import ctypes

''' XOR List.

An XOR linked list is a more memory efficient doubly linked list.

Instead of each node holding next and prev fields, it holds a field named both, 
which is an XOR of the next node and the previous node. 

Implement an XOR linked list; it has:

add(element) which adds the element to the end, and a
get(index) which returns the node at index.

'''

class XorLinkedList(object):

    class Node(object):
        def __init__(self, val):
            self.val = val
            self.both = 0
            
    def __init__(self):
        self.head = self.tail = None
        self.__nodes = [] # prevent garbage collection

    def add(self, value):
        
        node = self.Node(value)

        if self.head is None:
            self.head = self.tail = node
        else:
            self.tail.both = id(node) ^ self.tail.both
            node.both = id(self.tail)
            self.tail = node
        
        # Without this line, Python thinks there is no way to reach nodes between
        # head and tail
        self.__nodes.append(node)

    def get(self, index):
        
        prev_id = 0
        node = self.head
        
        for i in range(index):
            next_id = prev_id ^ node.both

            if next_id:
                prev_id = id(node)
                node = _get_obj(next_id)
            else:
                raise IndexError('Linked list index out of range')
        
        return node.val
    
    @staticmethod
    def _get_obj(id):
        return ctypes.cast(id, ctypes.py_object).value
