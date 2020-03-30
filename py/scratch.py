'''Check Subtree.

T1 and T2 are two very large binary trees, with T1 being much bigger
than T2. Create an algorithm to determine if T2 is a subtree of T1.

A tree T2 is a subtree of T1 if there exists a node n in T1 such that
the subtree of n is identical to T2. That is, if you cut off the
tree at node n, the two trees would be identical.
'''

from problems.tree import Node

def check_subtree(t1, t2):

    class ListNode():

        def __init__(self, data):
            self.data = data
            self.next = None
            
    def get_nodes(node):
        ''' creates an in order list from a tree node'''
        if node == None:
            return None
        
        head = None

        left = get_nodes(node.left)

        if left:
            head = left

        current = ListNode(node.data)

        if left:
            prev = head
            while prev.next != None:
                prev = prev.next
            prev.next = current
        else:
            head = current

        right = get_nodes(node.right)

        if right:
            current.next = right

        if not left and right:
            current.left = ListNode('-')
        elif left and not right:
            current.right = ListNode('-')

        return head

    if not (t1 and t2): return False

    head1 = get_nodes(t1)
    head2 = get_nodes(t2)

    head2 = head2.next

    while head1 and head1.data != head2.data:
        head1 = head1.next

    exists = True

    while head2 != None:
        exists &= head1.data == head2.data

        head1, head2 = head1.next, head2.next

    return exists 

t1 = Node(50)

t1.left = Node(30)
t1.left.left = Node(20)
t1.left.left.right = Node(25)
t1.left.right = Node(40)

t1.right = Node(70)
t1.right.left = Node(60)
t1.right.left.left = Node(55)
t1.right.left.right = Node(65)

t1.right.right = Node(80)
t1.right.right.left = Node(75)
t1.right.right.right = Node(90)

t2 = Node(60)
t2.left = Node(55)
# t2.right = Node(65)

exists = check_subtree(t1, t2)

print(exists)