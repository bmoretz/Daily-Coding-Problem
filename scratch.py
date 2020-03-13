'''Loop Detection.

Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

Definition:

Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
as to make a loop in the linked list.

Example:

Input: A -> B -> C -> D -> E -> C [the same C as earlier]
Output: C
'''

from problems.linkedlist import build_ref_list

def set_loop(node, loop_back):

    loop_node, prev = None, None

    while node != None:
        if node.data == loop_back:
            loop_node = node
        prev = node
        node = node.next

    prev.next = loop_node    

def detect_loop(node):
    if node == None: return None

    nodes = set()

    while node != None:
        
        if node in nodes:
            return node

        nodes.add(node)

        node = node.next

    return None

head = build_ref_list(['A', 'B', 'C', 'D', 'E'])

# set_loop(head, 'C')

loop_node = detect_loop(head)

print(loop_node)