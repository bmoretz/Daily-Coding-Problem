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