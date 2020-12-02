
'''
708. Insert into a Sorted Circular Linked List.

Given a node from a Circular Linked List which is sorted in ascending order, write a function to insert a 
value insertVal into the list such that it remains a sorted circular list. The given node can be a reference to 
any single node in the list, and may not be necessarily the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new 
value. After the insertion, the circular list should remain sorted.

If the list is empty (i.e., given node is null), you should create a new single circular list and return the reference to 
that single node. Otherwise, you should return the original given node.

Example 1:

Input: head = [3,4,1], insertVal = 2
Output: [3,4,1,2]

Explanation: In the figure above, there is a sorted circular list of three elements. You are given a reference to 
the node with value 3, and we need to insert 2 into the list. The new node should be inserted between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.

Example 2:

Input: head = [], insertVal = 1
Output: [1]
Explanation: The list is empty (given head is null). We create a new single circular list and return the reference to that single node.
Example 3:

Input: head = [1], insertVal = 0
Output: [1,0]

Constraints:

0 <= Number of Nodes <= 5 * 10^4
-10^6 <= Node.val <= 10^6
-10^6 <= insertVal <= 10^6
'''

class circular_insert:

    from typing import List

    class ListNode:
        def __init__(self, val=None, next=None):
            self.val = val
            self.next = next
    
    def make_list(self, values : List[int] ) -> ListNode:

        sentinel = self.ListNode()
        node = sentinel

        for val in values:
            node.next = self.ListNode(val)
            node = node.next
        
        node.next = sentinel.next

        return sentinel.next

    def to_list(self, head) -> List[int]:

        node, result = head, []

        while True:
            
            result.append(node.val)
            node = node.next

            if node == head:
                break

        return result

    def insert(self, head: ListNode, insertVal: int) -> ListNode:
        
        new_node = self.ListNode( insertVal )
        new_node.next = new_node
        
        if not head:
            return new_node
        
        prev, cur = head, head.next
        to_insert = False
        
        while True:
            
            if prev.val <= insertVal <= cur.val:
                to_insert = True
            elif prev.val > cur.val:
                if insertVal >= prev.val or insertVal <= cur.val:
                    to_insert = True
                    
            if to_insert:
                prev.next = self.ListNode(insertVal, cur)
                return head
            
            prev, cur = cur, cur.next
            
            if prev == head:
                break
        
        prev.next = self.ListNode(insertVal, cur)
        
        return head


head = circular_insert().make_list([3,4,1])

new_list = circular_insert().insert(head, 2)

actual = circular_insert().to_list(new_list)

expected = [3,4,1,2]