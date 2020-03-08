'''Return Kth to last.

Implement an algorithm to find the kth to last element of a singly linked list.
'''

from problems.linkedlist import build_list

class Node():
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

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

values = build_list([1, 2, 3, 4, 5, 6, 7])

target = klast2(values, 6)


print(target)
