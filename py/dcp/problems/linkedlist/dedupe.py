'''Remove Duplicates.

Write code to remove duplicates from an unsorted linked list.

How about if a temporary buffer is not allowed?
'''

from .node import Node

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