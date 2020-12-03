
'''
138. Copy List with Random Pointer.

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
The number of nodes will not exceed 1000.
'''

class deep_copy_random:

    from typing import List
    class ListNode:

        def __init__(self, val, nxt : 'ListNode' = None, random : 'ListNode' = None) -> 'ListNode':
            self.val = val
            self.next = nxt
            self.random = random

    def build_random_list(self, values : List[List[int]]) -> ListNode:

        sentinel = self.ListNode(0)
        node, nodes = sentinel, {}

        for index, val in enumerate(values):
            node.next = self.ListNode(val[0])
            node = node.next

            nodes[index] = node

        for index, val in enumerate(values):
            
            rnd_ptr = val[1]

            if rnd_ptr:
                nodes[index].random = nodes[rnd_ptr]

        return sentinel.next

    def copyRandomList(self, head: 'Node') -> 'Node':
        
        sentinel = self.ListNode
        new_node = sentinel
        
        node, seen = head, {}
        
        while node:
            
            new_node.next = self.ListNode(node.val)
            
            seen[node] = new_node.next
            node, new_node = node.next, new_node.next
            
            
        node = head
        
        for index in range(len(seen)):
            
            if node.random:
                seen[node].random = seen[node.random]
            
            node = node.next
            
        return sentinel.next


list_str = [[7,None],[13,0],[11,4],[10,2],[1,0]]
head = deep_copy_random().build_random_list(list_str)

new_head = deep_copy_random().copyRandomList(head)

old, new = head, new_head

while old or new:

    assert old.val == new.val

    if old.random or new.random:
        assert old.random.val == new.random.val

    old, new = old.next, new.next