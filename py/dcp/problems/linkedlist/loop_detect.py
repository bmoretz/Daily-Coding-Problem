'''Loop Detection.

Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

Definition:

Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
as to make a loop in the linked list.

Example:

Input: A -> B -> C -> D -> E -> C [the same C as earlier]
Output: C
'''

def detect_loop1(node):
    if node == None: return None

    nodes = set()

    while node != None:
        
        if node in nodes:
            return node

        nodes.add(node)

        node = node.next

    return None