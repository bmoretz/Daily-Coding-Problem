"""
430. Flatten a Multilevel Doubly Linked List.

You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer,
which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own,
and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are 
given the head of the first level of the list.

Example 1:

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:

After flattening the multilevel linked list it becomes:

Example 2:

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:

The input multilevel linked list is as follows:

  1---2---NULL
  |
  3---NULL
Example 3:

Input: head = []
Output: []

How multilevel linked list is represented in test case:

We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 
Constraints:

Number of Nodes will not exceed 1000.
1 <= Node.val <= 10^5
"""

class ListNode:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
    
def __str__(self):
    return self.val

def flatten_rec( head : ListNode) -> ListNode:
    """
    flattens a nested linked list (recursively)

    Args:
        head (ListNode): head ptr

    Returns:
        ListNode: flattened list

    """
    def flatten(head: ListNode) -> ListNode:

        sentinel = ListNode(0, None, None, None)
        flat, node, prev = sentinel, head, None
        
        while node:
            
            flat.next = ListNode(node.val,prev,None,None)
            flat = flat.next
            
            if node.child:
                flat.next = flatten(node.child)
                flat.next.prev = flat
                
                while flat.next:
                    flat = flat.next
                
                prev = flat
            else:
                prev = node
                
            node = node.next
            
        return sentinel.next

    return flatten(head)

def flatten_iter(head : ListNode) -> ListNode:
    """
    flattens a nested linked list (iteratively)

    Args:
        head (ListNode): head ptr

    Returns:
        ListNode: flattened list

    """
    def flatten(head: ListNode) -> ListNode:
        
        node, _ = head, None
        stack = []

        while node:

            # if the node has a child node    
            if node.child:

                if node.next:
                    # save the normal next node before
                    # we flatten out the sublist
                    stack.append( node.next )
                
                # next now points to the child node so it flattens out
                # we also need to update the child nodes prev node to point to
                # the current node
                node.next, node.next.prev = node.child, node
            
            # if we reach the end of a sublist (no valid next ptr) and
            # we have valid next nodes in our stack
            if not node.next and stack:
                # update the next ptr to point to the top of the stack
                # and then update its prev ptr to the current node
                node.next, node.next.prev = stack.pop(), node
            
            # normal traversal, save prev node, move the current node fwd
            # and clear out the child ptr (if one) to satisfy the problem's
            # definition of a 'valid double linked list'
            _, node.child, node = node, None, node.next
            
        return head

    return flatten(head)