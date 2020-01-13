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

        while( c != None ):
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

'''3.2
We can represent an integer in a linked list format by having each node represent a digit in the number. The nodes are connected in reverse order, such that the number

54321

is represented by the following linked list:

1 -> 2 -> 3 -> 4 -> 5

Given two linked lists in this format, return their sum.

for example,

9 -> 9
5 -> 2

Should return 124 (4 -> 2 -> 1)
'''
def add_numbers(list1, list2):
    result = SLinkedList()
    
    # storage for current elements and remainder
    e1, e2, rem = list1.head, list2.head, 0

    while e1 != None or e2 != None or rem != 0:

        v1 = 0 if e1 is None else e1.data
        v2 = 0 if e2 is None else e2.data

        current = v1 + v2 + rem

        value = current % 10
        rem = 0 if e1 == None or e2 == None else int( current / 10)

        result.push_back( value )
        
        e1 = None if e1 is None else e1.get_next()
        e2 = None if e2 is None else e2.get_next()

    return result