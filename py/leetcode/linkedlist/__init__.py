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

int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new 
    node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index 
    equals the length of the linked list, the node will be appended 
    to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 
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