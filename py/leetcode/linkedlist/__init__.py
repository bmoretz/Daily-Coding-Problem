from typing import List

'''
141. Linked List Cycle.

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.

Follow up: Can you solve it using O(1) (i.e. constant) memory?
'''

''' O(N) run-time, O(N) memory.'''
class has_cycle1:
    
    class ListNode:
        def __init__(self, x):
            self.val = x
            self.next = None
                
    def hasCycle(self, head: ListNode) -> bool:
        
        seen = set()
        node = head
        
        while node:
            
            if node in seen:
                return True
            
            seen.add( node )
            node = node.next
            
        return False

'''O(N) run-time, O(1) memory'''
class has_cycle2:
    
    class ListNode:
        def __init__(self, x):
            self.val = x
            self.next = None

    def hasCycle(self, head: ListNode) -> bool:
        
        if not head: return False
        
        slow, fast = head, head.next
        
        while slow != fast:
            
            if not fast or not fast.next:
                return False
            
            slow = slow.next
            fast = fast.next.next
            
        return True

'''
160. Intersection of Two Linked Lists.

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

begin to intersect at node c1.

Example 1:

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, 
it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

Example 2:

Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [1,9,1,2,4]. From the 
head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

Example 3:

Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, 
intersectVal must be 0, while skipA and skipB can be arbitrary values.

Explanation: The two lists do not intersect, so return null.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Each value on each linked list is in the range [1, 10^9].
Your code should preferably run in O(n) time and use only O(1) memory.
'''

class intersection:

    class ListNode:
        def __init__(self, x):
            self.val = x
            self.next = None

    def to_list(self, values) -> ListNode:

        sentinel = self.ListNode(0)
        node = sentinel

        for val in values:
            node.next = self.ListNode(val)
            node = node.next
        
        return (sentinel.next, node)
        
    def build_list( self, list1 : List[int], list2 : List[int], common : List[int] ) -> (ListNode, ListNode, ListNode):
        
        headA, tailA = self.to_list( list1 )
        headB, tailB = self.to_list( list2 )

        tail, _ = self.to_list( common )

        tailA.next = tail
        tailB.next = tail

        return (headA, headB, tail)

    def to_set( self, head : ListNode ) -> set():
        seen = set()
        node = head
        
        while node:
            seen.add( node )
            node = node.next
        
        return seen
    
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
            
        seen = self.to_set(headA)
        
        node = headB
        
        while node:
            
            if node in seen:
                return node
            
            node = node.next
            
        return None