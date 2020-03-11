'''Sum List:

You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit
is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

Example:

Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
Output: 2 -> 1 -> 9. That is, 912.

Follow up:

Suppose the digits are stored in forward order. Repeat the problem.

Example:

Input: (6 -> 1 -> 7) + (2 + 9 + 5). That is, 617 + 295.
Output: 9 -> 1 -> 2. That is, 912.
'''

from problems.linkedlist import build_list

class Node():

    def __init__(self, data, next=None):
        self.data = data
        self.next = next

def fwd_sum1(n1, n2):
    
    def rev(node):

        prev = None

        while node != None:
            
            nxt = node.next
            node.next = prev
            prev = node
            node = nxt
            
        return prev

    if n1 == None or n2 == None: return None

    h1, h2 = rev(n1), rev(n2)
    
    node, carry = None, 0

    while h1 != None  or h2 != None or carry != 0:
        digit1 = h1.data if h1 else 0
        digit2 = h2.data if h2 else 0        

        value = digit1 + digit2 + carry
        
        node = Node(value % 10, node)

        carry = 1 if value > 9 else 0
        
        h1, h2 = h1.next if h1 else None, h2.next if h2 else None

    return node

n1, n2 = build_list([6, 1, 7]), build_list([3, 9, 5])

fwdsum = fwd_sum1(n1, n2)

while fwdsum != None:
    print(fwdsum.data)
    fwdsum = fwdsum.next


