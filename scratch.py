from problems.linkedlist import Node, SLinkedList

'''3.4
Given two singly linked lists that intersect at some point, find the intersecting node.

Assume the lists are non-cyclical.

For example, given 

A = 3 -> 7 -> 8 -> 10, B = 99 -> 1 -> 8 -> 10

return the node with value 8. In this example, assume nodes with the same value are the exact same objects.

Do this in O(m + n) time (where m and n are the lenghts of the list) and constant space.
'''

'''Problem Setup'''
listA, listB = SLinkedList(), SLinkedList()

listA.push_back(3)
listA.push_back(7)
listA.push_back(8)
listA.push_back(10)

listB.push_back(99)
listB.push_back(1)
listB.push_back(8)
listB.push_back(10)

# if not listA or not listB: return None

a, b = listA.head, listB.head

while a != b:

    if not a: a = listB.head
    else: a = a.next

    if not b: b = listA.head
    else: b = b.next

print(a)