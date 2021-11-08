
'''
206. Reverse Linked List.

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
'''

class ListNode:
    def __init__(self, val):
        self.next = None
        self.val = val

def build_list(values : list[int] ) -> ListNode:
    
    sentinel = ListNode(0)
    node = sentinel

    for value in values:
        node.next = ListNode(value)
        node = node.next

    return sentinel.next

def to_list(head : ListNode) -> list[int]:

    node, result = head, []

    while node:
        result += [node.val]
        node = node.next

    return result

def reverseList_iter(head: ListNode) -> ListNode:

    node, prev = head, None
    
    while node:
        
        tmp = node.next
        node.next = prev
        
        prev = node
        node = tmp
        
    return prev

def reverseList_rec(self, head: ListNode ) -> ListNode:

    if not head or not head.next: return head

    node = self.reverseList_rec(head.next)

    head.next.next = head
    head.next = None

    return node