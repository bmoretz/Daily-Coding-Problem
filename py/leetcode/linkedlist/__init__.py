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

'''
206. Reverse Linked List.

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
'''

class rev_linkedlist:

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

    def reverseList_iter(self, head: ListNode) -> ListNode:
    
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

class even_odd_linkedlist:

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

    def oddEvenList(self, head: ListNode) -> ListNode:
        
        if head == None or head.next == None: return head
        
        even_head, odd_head = head.next, head
        even, odd = even_head, odd_head
        
        node = head.next.next
        index = 1
        
        while node:
            
            if index % 2 == 0:
                even.next = node
                even = even.next
            else:
                odd.next = node
                odd = odd.next
                
            index += 1
            node = node.next
            
        even.next = None
        odd.next = even_head
        
        return odd_head

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

'''
707. Design Linked List.

Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a 
pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to 
indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.

int get(int index) Get the value of the index^th node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new 
    node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the index^th node in the linked list. If index 
    equals the length of the linked list, the node will be appended 
    to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the index^th node in the linked list, if the index is valid.
 
Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 
Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.
'''

class DoubleLinkedList:

    class ListNode:
        
        def __init__(self, val : int,prev=None,nxt=None):
            self.prev, self.next = prev, nxt
            self.value = val
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head, self.tail = self.ListNode(0), self.ListNode(0)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        
        node, pos = self.head.next, 0
        
        while node and pos < index:
            node, pos = node.next, pos + 1
            
        return node.value if node and node != self.tail else -1
    
    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After 
        the insertion, the new node will be the first node of the linked list.
        """
        
        new_node = self.ListNode(val, self.head, self.head.next)

        self.head.next.prev, self.head.next = new_node, new_node
        
    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        
        new_node = self.ListNode(val,self.tail.prev,self.tail)

        self.tail.prev.next, self.tail.prev = new_node, new_node

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index 
        equals to the length of linked list, the node will be appended to the end of 
        linked list. If index is greater than the length, the node will not be inserted.
        """
    
        node, cur = self.head.next, 0
        
        while node and cur < index:
            if not node: return
            node = node.next
            cur += 1
        
        if not node: return
        
        new_node = self.ListNode(val, node.prev, node)
        node.prev.next, node.prev = new_node, new_node
        
    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        
        node, cur = self.head.next, 0
        
        while node and cur < index:
            if not node: return
            node = node.next
            cur += 1
        
        if not node or node == self.tail: return
        
        node.prev.next, node.next.prev = node.next, node.prev

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

class add_two_numbers:

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

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        sentinel = self.ListNode(0)
        node, carry = sentinel, 0
        
        while l1 or l2 or carry:
            
            left = l1.val if l1 else 0
            right = l2.val if l2 else 0
            
            val = left + right + carry
            
            node.next = self.ListNode( val % 10 )
            node = node.next
            
            carry = 1 if val > 9 else 0
            
            l1, l2 = l1.next if l1 else None, l2.next if l2 else None
            
        return sentinel.next


'''
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
'''

''' Recursive Version '''
class flatten_nested_list_rec:

    class ListNode:
        def __init__(self, val, prev, next, child):
            self.val = val
            self.prev = prev
            self.next = next
            self.child = child
        
    def __str__(self):
        return self.val

    def flatten(self, head: ListNode) -> ListNode:
    
        sentinel = self.ListNode(0, None, None, None)
        flat, node, prev = sentinel, head, None
        
        while node:
            
            flat.next = self.ListNode(node.val,prev,None,None)
            flat = flat.next
            
            if node.child:
                flat.next = self.flatten(node.child)
                flat.next.prev = flat
                
                while flat.next:
                    flat = flat.next
                
                prev = flat
            else:
                prev = node
                
            node = node.next
            
        return sentinel.next

''' Iterative Version w/ Stack '''
class flatten_nested_list_iter:
    
    class Node:
        def __init__(self, val, prev, next, child):
            self.val = val
            self.prev = prev
            self.next = next
            self.child = child
        
    def __str__(self):
        return self.val

    def flatten(self, head: Node) -> Node:
        
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