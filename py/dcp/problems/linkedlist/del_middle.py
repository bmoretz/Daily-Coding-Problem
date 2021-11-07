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