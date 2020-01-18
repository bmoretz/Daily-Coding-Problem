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
list1, list2 = SLinkedList(), SLinkedList()


list1.push_back(3)
list1.push_back(7)
list1.push_back(8)
list1.push_back(10)

list2.push_back(99)
list2.push_back(1)
list2.push_back(8)
list2.push_back(10)

'''O(m + n) Solution'''
def intersect1(list1, list2):
    vals = dict()

    for item in list1.elements():
        vals.setdefault(item, [])

    for item in list2.elements():
        if item in vals:
            return item


print(intersect1(list1, list2))