'''
21. Merge Two Sorted Lists.

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example 1:

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
'''

class merge_sorted_lists:

    from typing import List
    class ListNode:

        def __init__(self, val : int ):
            self.val = val
            self.next = None
    
    def build_list(self, values : List[int] ) -> ListNode:

        sentinel = self.ListNode(0)
        node = sentinel

        for val in values:
            node.next = self.ListNode(val)
            node = node.next

        return sentinel.next

    def to_vector(self, head : ListNode ) -> List[int]:

        node, result = head, []

        while node:
            result.append(node.val)
            node = node.next

        return result

    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        sentinel = self.ListNode(0)
        node = sentinel
        
        l_node, r_node = l1, l2
        
        while l_node or r_node:
            
            left = l_node.val if l_node else float('inf')
            right = r_node.val if r_node else float('inf')
            
            if left <= right:
                node.next = self.ListNode(left)
                l_node = l_node.next
            else:
                node.next = self.ListNode(right)
                r_node = r_node.next
                
            node = node.next
            
        return sentinel.next