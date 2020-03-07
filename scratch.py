'''Remove Duplicates.

Write code to remove duplicates from an unsorted linked list.

How about if a temporary buffer is not allowed?
'''

from problems.linkedlist import build_list

class Node():
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

''' O(N^2) run-time, O(1) space. '''

def dedup2(node):

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

values = build_list([1, 2, 3, 4, 3, 5, 2])

unique = dedup2(values)

print(values)

print(unique)