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
l1, l2 = SLinkedList(), SLinkedList()

for x in [3, 7, 8, 10]: l1.push_back(x)
for x in [99, 1, 8, 10]: l2.push_back(x)

m, n = l1.length(), l2.length()
cur_a, cur_b = l1.head, l2.head

if m > n:
    for _ in range(m - n):
        cur_a = cur_a.next
else:
    for _ in range(n - m):
        cur_b = cur_b.next

while(cur_a != cur_b):
    cur_a = cur_a.next
    cur_b = cur_b.next

print(cur_a)