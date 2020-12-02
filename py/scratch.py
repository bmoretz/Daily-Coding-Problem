
'''
2. Add Two Numbers.

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in 
reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself. 

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
'''

''' Iterative Version w/ Stack '''
class Solution:
    class Node:
        def __init__(self, val, prev, next, child):
            self.val = val
            self.prev = prev
            self.next = next
            self.child = child
        
    def __str__(self):
        return self.val

    def flatten(self, head: 'Node') -> 'Node':
        
        node, prev = head, None
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
            prev, node.child, node = node, None, node.next
            
        return head