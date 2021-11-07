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