from .node import Node

'''Singly Linked List Implementation.'''
class SLinkedList:
    
    def __init__(self):
        self.head = None
        self.last = None

    '''O(1) - insert @ tail'''
    def push_back(self, data):

        node = Node(data)

        if self.head == None:
            self.head, self.last = node, node          
        else:
            tmp = self.last
            self.last, tmp.next = node, node

    '''O(n) get elements'''
    def elements(self):
        
        result = []
        c = self.head

        while( c != None ):
            result.append(c.data)
            c = c.get_next()
        
        return result
    
    '''O(n) - length'''
    def length(self):

        current, length = self.head, 0

        while current is not None:
            length += 1
            current = current.next

        return length

    '''Reverse Linked List.

    Given the head of a singly linked list, reverse it in-place.

    O(N) Solution
    '''
    def reverse(self):

        prev, current = None, self.head

        while current != None:
            tmp = current.next
            current.next = prev
            prev = current
            current = tmp
        
        self.head = prev

    '''O(N) - to string'''
    def __str__(self):
        
        result = ""

        c = self.head

        while( c != None ):
            result = result + "[{}]".format(c.get_data())
            c = c.get_next()

        return result

def initialize(ll, vals):
    for x in vals: ll.push_back(x)

def build_list(values):

    head, prev = None, None

    for value in values:
        node = Node(value)

        if head == None:
            head, prev = node, node
        else:
            prev.next = node

        prev = node
        
    return head