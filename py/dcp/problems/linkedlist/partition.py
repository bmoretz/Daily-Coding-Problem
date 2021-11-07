'''Partition.

Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x.

If x is contained within the list, the values of x only need to be after the elements less than x. The partition element x can appear
anywhere in the "right partition"; it does not need to appear between the left and right partitions.

Example:

Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
'''

''' O(N) run-time, O(N) space.'''
def partition1(node, partition):

    if node == None or partition == None: return None

    lhead, uhead = None, None
    lower, upper = None, None

    while node != None:

        if node.data < partition:

            if lower == None:
                lower, lhead = node, node
            else:
                lower.next = node
                lower = lower.next

        if node.data >= partition:

            if upper == None:
                upper, uhead = node, node
            else:
                upper.next = node
                upper = upper.next
            
        node = node.next

    if upper != None:
        upper.next = None

    if lower != None:
        lower.next = uhead

    return lhead if lhead != None else uhead