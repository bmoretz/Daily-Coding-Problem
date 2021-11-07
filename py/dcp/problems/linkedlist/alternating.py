'''Alternating Linked List.

Given a linked list, rearrange the node values such that they appear in alternating

low -> high -> low -> high ... form.

For example, 

given 1 -> 2 -> 3 -> 4 -> 5, 

you should return

1 -> 3 -> 2 -> 5 -> 4
'''

from .single import SLinkedList

'''O(n) Solution'''
def alternate1(items):
    is_low, result = True, SLinkedList()

    p, c = None, items.head
    n = c.get_next()

    while c != None:
        
        items = [x for x in [ c.data, p.data if p != None else None, n.data if n != None else None ] if x is not None]

        if is_low:
            i = min( items )
        else:
            i = max( items )

        result.push_back( i )

        p, is_low = c, not is_low
        c, n = c.get_next(), n.get_next() if n is not None else None

    return result

'''O(n) Solution'''
def alternate2(items):
    even = True
    cur = items.head

    while cur.next:
        if cur.data > cur.next.data and even:
            cur.data, cur.next.data = cur.next.data, cur.data
        
        elif cur.data < cur.next.data and not even:
            cur.data, cur.next.data = cur.next.data, cur.data

        even = not even
        cur = cur.next

    return items