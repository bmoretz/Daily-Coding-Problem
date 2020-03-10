'''Partition.

Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x.

If x is contained within the list, the values of x only need to be after the elements less than x. The partition element x can appear
anywhere in the "right partition"; it does not need to appear between the left and right partitions.
'''

from problems.linkedlist import build_list

class Node():
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

def delete_middle1(node):
    
    if node == None: return None

    prev = None

    while node.next != None:
        node.next.data, node.data = node.data, node.next.data
        prev = node
        node = node.next

    if prev != None:
        prev.next = None

head, target = build_list(['a', 'b', 'c', 'd', 'e', 'f']), 'f'

node = head

while node.data != target:
    node = node.next

delete_middle1(node)

node = head

while node != None:
    print(node.data)
    node = node.next
