'''Generic Node Class.'''
class Node:

    def __init__(self, data, next = None):
        self.data = data
        self.next = next

    def __str__(self):
        return "{}".format(self.data) 

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def set_data(self, data):
        self.data = data

    def set_next(self, node):
        self.next = node

'''Singly Linked List Implementation.'''
class SLinkedList:
    
    def __init__(self):
        self.head = None

    '''O(N) - Insert'''
    def push_back(self, data):

        node = Node(data)

        if self.head == None:
            self.head = node
        else:
            c = self.head
            
            while( c.get_next() != None ):
                c = c.get_next()

            c.next = node

    def elements(self):
        
        result = []
        c = self.head

        while( c.get_next() != None ):
            result.append(c.data)
            c = c.get_next()
        
        return result

    '''3.1
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