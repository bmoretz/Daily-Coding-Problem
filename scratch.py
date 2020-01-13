'''3.2
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

from problems.linkedlist import Node, SLinkedList

# problem setup

l1, l2, result = SLinkedList(), SLinkedList(), SLinkedList()

l1.push_back(9)
l1.push_back(9)

l2.push_back(5)
l2.push_back(2)

# storage for current elements and remainder
e1, e2, rem = l1.head, l2.head, 0

while e1 != None or e2 != None or rem != 0:

    v1 = 0 if e1 is None else e1.data
    v2 = 0 if e2 is None else e2.data

    current = v1 + v2 + rem

    value = current % 10
    rem = 0 if e1 == None or e2 == None else int( current / 10)

    result.push_back( value )
    
    e1 = None if e1 is None else e1.get_next()
    e2 = None if e2 is None else e2.get_next()


print( result.elements() )