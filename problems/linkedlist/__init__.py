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
    
    '''O(n) - length'''
    def length(self):

        current, length = self.head, 0

        while current is not None:
            length += 1
            current = current.next

        return length

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

'''O(n + m) solution #1'''
def add_numbers1(list1, list2):
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

'''O(n + m) Solution #2'''
def add_numbers2(node0, node1, carry = 0):

    if not node0 and not node1 and not carry:
        return None
    
    node0_val = node0.data if node0 else 0
    node1_val = node1.data if node1 else 0
    total = node0_val + node1_val + carry

    node0_next = node0.next if node0 else None
    node1_next = node1.next if node1 else None
    carry_next = 1 if total >= 10 else 0

    return Node(total % 10, add_numbers2(node0_next, node1_next, carry_next))

'''3.3
Given a linked list, rearrange the node values such that they appear in alternating

low -> high -> low -> high ... form.

For example, 

given 1 -> 2 -> 3 -> 4 -> 5, 

you should return

1 -> 3 -> 2 -> 5 -> 4
'''

'''O(n) Solution'''
def alternate1(items):
    is_low, result = True, SLinkedList()

    p, c = None, items.head
    n = c.get_next()

    while c != None:
        
        items = [x for x in [ c.data, p.data if p != None else None, n.data if n != None else None ] if x is not None]

        if is_low:
            i = min( items )
        else:
            i = max( items )

        result.push_back( i )

        p, is_low = c, not is_low
        c, n = c.get_next(), n.get_next() if n is not None else None

    return result

'''O(n) Solution'''
def alternate2(items):
    even = True
    cur = items.head

    while cur.next:
        if cur.data > cur.next.data and even:
            cur.data, cur.next.data = cur.next.data, cur.data
        
        elif cur.data < cur.next.data and not even:
            cur.data, cur.next.data = cur.next.data, cur.data

        even = not even
        cur = cur.next

    return items

'''3.4
Given two singly linked lists that intersect at some point, find the intersecting node.

Assume the lists are non-cyclical.

For example, given 

A = 3 -> 7 -> 8 -> 10, B = 99 -> 1 -> 8 -> 10

return the node with value 8. In this example, assume nodes with the same value are the exact same objects.

Do this in O(m + n) time (where m and n are the lenghts of the list) and constant space.
'''

'''O(m + n) Solution'''
def intersect1(list1, list2):
    vals = dict()

    for item in list1.elements():
        vals.setdefault(item, [])

    for item in list2.elements():
        if item in vals:
            return item