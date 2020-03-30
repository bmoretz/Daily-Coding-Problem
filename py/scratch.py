'''Check Subtree.

T1 and T2 are two very large binary trees, with T1 being much bigger
than T2. Create an algorithm to determine if T2 is a subtree of T1.

A tree T2 is a subtree of T1 if there exists a node n in T1 such that
the subtree of n is identical to T2. That is, if you cut off the
tree at node n, the two trees would be identical.
'''

from problems.tree import Node

def check_subtree(t1, t2):

    def find(tree, node):
        
        if tree == None: return None
        
        if tree.data == node.data: 
            return tree

        left = find(tree.left, node)

        if left: 
            return left

        right = find(tree.right, node)

        if right: 
            return right

        return None

    def check_tree(tree1, tree2):

        if not (tree1 and tree2): return False

        if tree1.data != tree2.data:
            return False

        equal = True

        if tree1.left or tree2.left:
            equal &= check_tree(tree1.left, tree2.left)

        if tree1.right or tree2.right:
            equal &= check_tree(tree1.right, tree2.right)

        return equal
        
    if not (t1 and t2): return None

    # find t2 root in t1
    start = find(t1, t2)
    
    return check_tree(start, t2)

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
t2.right = Node(65)

exists = check_subtree(t1, t2)

print(exists)