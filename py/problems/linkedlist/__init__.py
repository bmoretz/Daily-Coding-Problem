'''Generic Node Class.'''
class Node:

    def __init__(self, data, next = None):
        self.data = data
        self.next = next

    def __str__(self):
        return "{}".format(self.data) 

    def __eq__(self, other):
        if isinstance(other, Node):
            return self.data == other.data
        
        return False

    def __ne__(self, other):
        result = self.__eq__(other)

        if result is NotImplemented:
            return result
        
        return not result

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def set_data(self, data):
        self.data = data

    def set_next(self, node):
        self.next = node

''' equality is by reference. '''
class RefNode():

    def __init__(self, data, next=None):
        self.data = data
        self.next = next

def build_ref_list(values):
    head, prev = None, None

    for val in values:
        node = RefNode(val)

        if head == None:            
            head, prev = node, node
        else:
            prev.next = node
            prev = node

    return head

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

''' Sum Linked List.

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

'''Alternating Linked List.

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

'''Linked List Intersection.

Given two singly linked lists that intersect at some point, find the intersecting node.

Assume the lists are non-cyclical.

For example, given 

A = 3 -> 7 -> 8 -> 10, B = 99 -> 1 -> 8 -> 10

return the node with value 8. In this example, assume nodes with the same value are the exact same objects.

Do this in O(m + n) time (where m and n are the lengths of the list) and constant space.
'''

'''O(m + n) Solution'''
def intersect1(list1, list2):
    vals = dict()

    for item in list1.elements():
        vals.setdefault(item, [])

    for item in list2.elements():
        if item in vals:
            return item

'''O(m + n) Solution'''
def intersect2(list1, list2):
    if not list1 or not list2: return None

    n1, n2 = list1.head, list2.head

    while n1 != n2:

        if not n1: n1 = list2.head
        else: n1 = n1.next

        if not n2: n2 = list1.head
        else: n2 = n2.next

    return n1

'''O(m + n) Solution'''
def intersect3(list1, list2):

    m, n = list1.length(), list2.length()
    cur_a, cur_b = list1.head, list2.head

    if m > n:
        for _ in range(m - n):
            cur_a = cur_a.next
    else:
        for _ in range(n - m):
            cur_b = cur_b.next

    while(cur_a != cur_b):
        cur_a = cur_a.next
        cur_b = cur_b.next

    return cur_a

'''O(N + M)'''
def intersect4(list1, list2):

    vals = []

    while list1 != None:
        vals += [list1.value]
        list1 = list1.next

    while list2 != None:
        if list2.value in vals:
            return list2.value

        list2 = list2.next

    return None

'''Remove Duplicates.

Write code to remove duplicates from an unsorted linked list.

How about if a temporary buffer is not allowed?
'''

''' O(N) run-time, O(N) space '''

def dedupe1(node):

    if node == None: return None

    values = set()
    head, prev = None, None

    while node != None:
        if node.data not in values:
            values.add(node.data)
            new = Node(node.data)
            
            if head == None:
                head, prev = new, new
            else:
                prev.next = new
                prev = prev.next

        node = node.next

    return head

''' O(N^2) run-time, O(1) space. '''
def dedupe2(node):

    def in_list(node, value):

        while node != None:

            if node.data == value:
                return True

            node = node.next

        return False

    if node == None: return None

    head, prev = None, None

    while node != None:
        
        if not in_list(head, node.data):
            new = Node(node.data)
            
            if head == None:
                head, prev = new, new
            else:
                prev.next = new
                prev = prev.next    
        
        node = node.next

    return head

'''Return Kth to last.

Implement an algorithm to find the kth to last element of a singly linked list.
'''

''' O(n) run-time, O(n) space. '''
def klast1(node, k):

    if node == None or k < 0: return None
    
    values = []

    while node != None:
        values += [node.data]
        node = node.next

    return values[len(values) - k - 1]

''' O(N) run-time, O(1) space '''
def klast2(node, k):
    
    if node == None or k < 0: return None
    
    target, index = None, 0

    head = node

    while node != None:
        
        if index - k - 1 == 0:
            target = head

        if target is not None:
            target = target.next

        index += 1
        node = node.next

    return target.data if target else head.data

'''Delete Middle Node.

Implement an algorithm to delete a node in the middle (i.e., any node but the first and last, not necessarily the exact middle) of
a singly linked list, given only access to that node.

Example:

Input: the node c from the linked list a -> b -> c -> d -> e -> f
Result: nothing is returned, but the new linked list looks like: a -> b -> d -> e -> f
'''

''' O(N) run-time, O(1) space.'''
def delete_middle1(node):
    
    if node == None: return None

    prev = None

    while node.next != None:
        node.next.data, node.data = node.data, node.next.data
        prev = node
        node = node.next

    if prev != None:
        prev.next = None

'''Partition.

Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x.

If x is contained within the list, the values of x only need to be after the elements less than x. The partition element x can appear
anywhere in the "right partition"; it does not need to appear between the left and right partitions.

Example:

Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
'''

''' O(N) run-time, O(N) space.'''
def partition1(node, partition):

    if node == None or partition == None: return None

    lhead, uhead = None, None
    lower, upper = None, None

    while node != None:

        if node.data < partition:

            if lower == None:
                lower, lhead = node, node
            else:
                lower.next = node
                lower = lower.next

        if node.data >= partition:

            if upper == None:
                upper, uhead = node, node
            else:
                upper.next = node
                upper = upper.next
            
        node = node.next

    if upper != None:
        upper.next = None

    if lower != None:
        lower.next = uhead

    return lhead if lhead != None else uhead

'''Sum List:

You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit
is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

Example:

Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
Output: 2 -> 1 -> 9. That is, 912.

Follow up:

Suppose the digits are stored in forward order. Repeat the problem.

Example:

Input: (6 -> 1 -> 7) + (2 + 9 + 5). That is, 617 + 295.
Output: 9 -> 1 -> 2. That is, 912.
'''

def rev_sum1(n1, n2):
    
    if n1 == None or n2 == None: return None

    prev, carry = None, 0
    
    while n1 != None or n2 != None or carry != 0:

        digit1 = n1.data if n1 != None else 0
        digit2 = n2.data if n2 != None else 0

        value = digit1 + digit2 + carry

        current = Node(value % 10)

        carry = 1 if value > 9 else 0

        if prev == None:
            prev = current
        else:
            current.next = prev
            prev = current

        n1, n2 = n1.next if n1 != None else None, n2.next if n2 != None else None

    return prev

def fwd_sum1(n1, n2):
    
    def rev(node):

        prev = None

        while node != None:
            
            nxt = node.next
            node.next = prev
            prev = node
            node = nxt
            
        return prev

    if n1 == None or n2 == None: return None

    h1, h2 = rev(n1), rev(n2)
    
    node, carry = None, 0

    while h1 != None  or h2 != None or carry != 0:
        digit1 = h1.data if h1 else 0
        digit2 = h2.data if h2 else 0        

        value = digit1 + digit2 + carry
        
        node = Node(value % 10, node)

        carry = 1 if value > 9 else 0
        
        h1, h2 = h1.next if h1 else None, h2.next if h2 else None

    return node

from copy import deepcopy

'''Palindrome.

Implement a function to check if a linked list is a palindrome.
'''

def is_palindrome1(node):
    
    def reverse(node):

        prev = None

        while node != None:

            nxt = node.next
            node.next = prev
            prev = node
            node = nxt
        
        return prev

    if node == None: return None

    orig = deepcopy(node)
    rev = reverse(node)

    is_pal = True

    while orig != None:
        is_pal &= orig.data == rev.data

        orig, rev = orig.next, rev.next

    return is_pal

'''Intersection.

Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node.

Note that the intersection is defined based on reference, not value. That is, if the kth node
of the first list is the exact same node (by reference), as the jth node of the second list,
then they are intersecting.
'''

def tail(node):
    if node == None: return None
    
    prev = None

    while node != None:
        prev = node
        node = node.next

    return prev

''' O(N^2) run-time, O(1) space.'''
def intersect5(node1, node2):

    if node1 == None or node2 == None: return None

    orig = node2

    while node1 != None:

        node2 = orig

        while node2 != None:

            if node1 == node2:
                return node1
            
            node2 = node2.next

        node1 = node1.next
    
    return None

''' O(N + K) run-time, O(1) space.'''
def intersect6(node1, node2):

    def tail_info(node):
        
        prev, length = None, 0
        
        while node != None:
            length += 1
            prev = node
            node = node.next
        
        return (prev, length)
    
    if node1 == None or node2 == None: return None

    i1, i2 = tail_info(node1), tail_info(node2)

    if i1[0] == i2[0]:
        return node1 if i1[1] < i2[1] else node2
         
    return None

'''Loop Detection.

Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

Definition:

Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
as to make a loop in the linked list.

Example:

Input: A -> B -> C -> D -> E -> C [the same C as earlier]
Output: C
'''

def detect_loop1(node):
    if node == None: return None

    nodes = set()

    while node != None:
        
        if node in nodes:
            return node

        nodes.add(node)

        node = node.next

    return None