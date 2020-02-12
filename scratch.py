class Node():
    
    def __init__(self, value, nxt = None):
        self.value = value
        self.next = nxt



A = Node(3, Node(7, Node(8, Node(10))))
B = Node(-99, Node(1, Node(8, Node(10))))


''' O(N * M)'''
def intersect1(lnode, rnode):

    l, r = lnode, rnode

    while l != None:

        while r != None:

            if l.value == r.value:
                return l

            r = r.next
        l = l.next
        r = rnode
    return None
                

def intersect2(lnode, rnode):

    left = []

    while lnode != None:
        left += [lnode.value]
        lnode = lnode.next

    while rnode != None:
        if rnode.value in left:
            return rnode.value

        rnode = rnode.next

    return None
    
int1 = intersect1(A, B)
int2 = intersect2(A, B)

print(int2)