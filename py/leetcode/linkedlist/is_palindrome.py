'''
328. Odd Even Linked List.

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
 

Constraints:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
The length of the linked list is between [0, 10^4].
'''

class is_palindrome:

    from typing import List

    class ListNode:
        def __init__(self, val):
            self.next = None
            self.val = val

    def build_list(self, values : List[int] ) -> ListNode:
        
        sentinel = self.ListNode(0)
        node = sentinel

        for value in values:
            node.next = self.ListNode(value)
            node = node.next

        return sentinel.next

    def to_list(self, head : ListNode ) -> List[int]:

        node, result = head, []

        while node:
            result += [node.val]
            node = node.next

        return result

    def isPalindrome(self, head: ListNode) -> bool:
        
        from queue import LifoQueue
        
        
        stack = LifoQueue()
        node = head
        
        while node:
            stack.put(node.val)
            node = node.next
            
        node = head

        while node:
            
            if node.val != stack.get():
                return False
            
            node = node.next
            
        return True