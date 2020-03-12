from copy import deepcopy

'''Palindrome.

Implement a function to check if a linked list is a palindrome.
'''

from problems.linkedlist import build_list


def is_palindrome(node):
    
    def reverse(node):

        prev = None

        while node != None:

            nxt = node.next
            node.next = prev
            prev = node
            node = nxt
        
        return prev

    if node == None: return None

    orig = deepcopy(node)
    rev = reverse(node)

    is_pal = True

    while orig != None:
        is_pal &= orig.data == rev.data

        orig, rev = orig.next, rev.next

    return is_pal

head = build_list(['a', 'b', 'c', 'b', 'a'])

print(is_palindrome(head))
