'''Intersection.

Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node.

Note that the intersection is defined based on reference, not value. That is, if the kth node
of the first list is the exact same node (by reference), as the jth node of the second list,
then they are intersecting.
'''

from problems.linkedlist import build_list


def tail(node):
    if node == None: return None
    
    prev = None

    while node != None:
        prev = node
        node = node.next

    return prev

h1 = build_list([1, 2, 3, 4])
h2 = build_list([5, 6])

#tail(h2).next = h1

def intersect6(node1, node2):

    def to_stack(node):

        stack = []

        while node != None:
            stack.append(node)
            node = node.next
        return stack

    def tail(node):
        
        prev = None
        
        while node != None:
            prev = node
            node = node.next
        
        return prev
    
    if node1 == None or node2 == None: return None

    s = to_stack(node1)

    return s[0] if s[-1] == tail(node2) else None

intersect = intersect(h1, h2)

print(intersect)