from problems.linkedlist import Node, SLinkedList

'''3.3
Given a linked list, rearrange the node values such that they appear in alternating

low -> high -> low -> high ... form.

For example, 

given 1 -> 2 -> 3 -> 4 -> 5, 

you should return

1 -> 3 -> 2 -> 5 -> 4
'''

'''Problem Setup'''
items = SLinkedList()

for index in range(1, 6):
    items.push_back(index)

'''O(n) Solution'''
def alt1(items):
    is_min, result = True, SLinkedList()

    p, c = None, items.head
    n = c.get_next()

    while c != None:

        if is_min:
            result.push_back( p.data if p is not None else c.data)
        else:
            result.push_back(n.data)

        is_min, p = not is_min, c
        c, n = c.get_next(), n.get_next() if n is not None else c.data
    return result

print(alt1(items).elements())