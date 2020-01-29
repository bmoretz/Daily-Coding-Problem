from problems.tree import Node
from problems.tree import populate_pre_order
from problems.tree import get_height, get_width

''' 1.29

An XOR linked list is a more memory efficent doubly linked list.

Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. 

Implement an XOR linked list; it has:

add(element) which adds the element to the end, and a
get(index) which returns the node at index.

'''


