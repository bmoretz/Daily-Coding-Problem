'''3.1
Given the head of a singly linked list, reverse it in-place.
'''

from problems.linkedlist import Node
from problems.linkedlist import SLinkedList

sl = SLinkedList()

for d in range(0, 10):
    sl.push_back(d)

print(sl)

print(sl.head.next)

sl.reverse()

print(sl)