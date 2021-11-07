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