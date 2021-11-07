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

from .node import Node
from .single import SLinkedList

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