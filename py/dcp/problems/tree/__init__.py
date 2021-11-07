
class Node:

    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        return f'<{self.data}, {self.left}, {self.right}>'

'''Return a (pre-ordered) tree from a given recursive list.'''
def populate_pre_order(data):
    
    if not data: return None

    node = Node(data[0])

    if len(data) > 1:
        node.left = populate_pre_order(data[1])
    
    if len(data) > 2:
        node.right = populate_pre_order(data[2])
        
    return node

'''Return the max height of a given tree.'''
def get_height(root):

    if not root: return 0

    left = get_height(root.left)
    right = get_height(root.right)

    return (left + 1) if (left > right) else (right + 1)

def get_width_rec(root, count, level):

    if root is not None:
        count[level] += 1
        get_width_rec(root.left, count, level + 1)
        get_width_rec(root.right, count, level + 1)

'''Return the max width of the tree.'''
def get_width(root):

    height = get_height(root)

    count, level = [0] * height, 0

    get_width_rec(root, count, level)

    _max = count[0]
    for index in range(len(count)):
        _max = max(_max, count[index])

    return _max

'''Count Unival Value.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the tree:

        0
    1       0
        1       0
    1       1

Should return 5.
'''

def is_unival(root):
    return unival_helper(root, root.data)

def unival_helper(root, value):

    if root is None:
        return True

    if root.data == value:
        return unival_helper(root.left, value) and \
            unival_helper(root.right, value)

    return False

'''O(n^2) count universal value subtrees'''
def count_unival_subtrees1(root):
    if root is None:
        return 0

    left = count_unival_subtrees1(root.left)
    right = count_unival_subtrees1(root.right)

    return (1 + left + right) if is_unival(root) else left + right

'''O(n^2) count universal value subtrees #2'''
def count_unival_subtrees2(tree):

    def is_univariate(node):

        if node.left == None and node.right == None: return True

        if node.left != None and node.right != None and \
            node.left.data == node.right.data == node.data:
            return True

        return False
    
    def count_univariate(root):

        if root == None: return 0

        value = 1 if is_univariate(root) else 0

        if root.left != None:
            value += count_univariate(root.left)

        if root.right != None:
            value += count_univariate(root.right)

        return value

    return count_univariate(tree)

'''Serialize Tree.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which will deserialize the string back into the tree.

'''

def serialize(node):

    if not node: return '#'

    return '{} {} {}'.format(node.data, serialize(node.left), serialize(node.right))

def deserialize(data):

    def helper():
        val = next(vals)
        
        if val == '#':
            return None
        
        node = Node(int(val))
        node.left = helper()
        node.right = helper()

        return node

    vals = iter(data.split())

    return helper()

''' Construct Tree.

Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

For example, given the following pre-order traversal:

[a, b, d, e, c, f, g]

And the following in-order traversal:

[d, b, e, a, f, c, g]

You should return the following tree:

        a
    b       c
d      e  f    g
'''

def reconstruct1(preorder, in_order):

    def reconstruct(preorder, in_order):
        if not preorder or not in_order: return None

        mid = round((len(in_order)) / 2)

        node = Node(preorder[0])

        left = preorder[1:mid]

        if left and mid != 0:
            node.left = reconstruct(left, left)

        right = preorder[mid:]

        if right and mid != 0: 
            node.right = reconstruct(right, right)

        return node

    return reconstruct(preorder, in_order)
    
def reconstruct2(preorder, in_order):

    def reconstruct(preorder, in_order):
        if not preorder and not in_order:
            return None

        root = Node(preorder[0])

        if len(preorder) == len(in_order) == 1:
            return root
 
        root_i = in_order.index(root.data) if len(in_order) > 1 else 0
        root.left = reconstruct(preorder[1:1 + root_i],
                                in_order[0:root_i])
        root.right = reconstruct(preorder[1 + root_i:],
                                        in_order[root_i + 1:])

        return root

    return reconstruct(preorder, in_order)


''' Evaluate Arithmetic.

Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of +, -, * or /.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

        *
    +       -
3      2 4    5

Should return 45, as it is (3 + 2) * (4 + 5).
'''

def evaluate1(root):

    operations = { 
        '+' : lambda x,y: x + y,
        '-' : lambda x,y: x - y,
        '*' : lambda x,y: x * y,
        '\\' : lambda x,y: x / y
    }

    def op(op, l, r):
        return operations[op](l, r) if op in operations.keys() else None

    def eval_node(node):
         return node.data if isinstance( node.data, int ) else evaluate(node)

    def evaluate(root):
        if not root: return None

        operation = root.data
        
        left = eval_node(root.left)

        right = eval_node(root.right)
        
        return op(operation, left, right)

    return evaluate(root)

'''Minimum Sum Tree.

Get tree level with minimum sum

Given a binary tree, return the level of the tree that has the minimum sum. The level of a node is defined as the number of connections required to get to the root, with the root having level zero.

For example,

        1
    2       3
        4       5

In this tree, level 0 has sum 1, level 1 has sum 5, and level 2 has sum 9, so the level with the minimum sum is zero.
'''

def minsum1(root):

    values = {}

    def evaluate(root, level = 1):
        if not root: return None
        
        if root.left or root.right: values[level] = 0

        if root.left:
            values[level] += root.left.data
            evaluate(root.left, level + 1)

        if root.right:
            values[level] += root.right.data
            evaluate(root.right, level + 1)

    if root: 
        values[0] = root.data
        evaluate(root)
    
    return min(values, key = values.get )


'''Minimal Tree.

Given a sorted (increasing order) array with unique integer elements, write
an algorithm to create a binary search tree with minimal height.
'''

class MinTree1():

    class Node():

        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None
        
        def is_full(self):
            return self.left != None and self.right != None

        def is_leaf(self):
            return self.left == None and self.right == None

    def __init__(self, values):
        self.root = None

        if values != None and len(values) > 0:
            self.root = self.__create_tree(values)

    def __create_tree(self, values):
        
        n = len(values)

        if n == 0: return None

        mid = n // 2

        root = self.Node(values[mid])

        if n > 1:
            root.left = self.__create_tree(values[:mid])
            root.right = self.__create_tree(values[mid + 1:])

        return root

    def height(self):

        def height(self, parent, level=0):
            
            if parent == None: 
                return level

            level = max(height(self, parent.left, level + 1), height(self, parent.right, level + 1))

            return level

        return height(self, self.root)

'''List of Depths.

Given a binary tree, design an algorithm which creates a linked list of all the nodes
at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
'''

class DepthList():

    class Node():
        def __init__(self, data):
            self.data = data
            self.next = None

    class BinaryTree():

        class Node():
            def __init__(self, data):
                self.data = data
                self.left = None
                self.right = None
                
        def __init__(self, values):
            self.root = None

            if len(values) > 0:
                self.root = self.__create_tree(values)

        def __create_tree(self, values):
            
            n = len(values)

            if n == 0: return None

            mid = n // 2

            root = self.Node(values[mid])

            if n > 1:
                root.left = self.__create_tree(values[:mid])
                root.right = self.__create_tree(values[mid + 1:])

            return root

        def height(self, node=None, level=0):
            
            if level == 0:
                node = self.root

            if node == None:
                return level

            level = max(self.height(node.left, level + 1), self.height(node.right, level + 1))

            return level

    def __init__(self, values):

        self.tree = None

        if values: self.tree = self.BinaryTree(values)

    ''' Solution #1
    
    This solution is iterative in nature. We process the current node
    building a linked list of values from the data in the tree nodes,
    and at the same time putting the children of that levels nodes
    into a seprate list to be processed during the next iteration.

    run-time: O(N), space: O(N) 
    '''

    def depth_list1(self):
        
        levels, nodes = [], [self.tree.root]

        while nodes:

            lvl = self.process_level(nodes)

            levels.append(lvl[0])
            nodes = lvl[1]

        return levels

    def process_level(self, nodes):
        
        children = []
        head, prev = None, None

        for node in nodes:
            
            ln = self.Node(node.data)

            if head == None:
                head, prev = ln, ln
            else:
                prev.next = ln

            if node.left: children.append(node.left)
            if node.right: children.append(node.right)

            prev = ln
        
        return (head, children)

    ''' Solution #2

    This solution is recursive in nature, processing each node independently.

    When we process a node, we check to see if the level has a linked list head
    element, if not we add it. Then, as we process the elements down the tree,
    we get the list associated with that level and traverse to the end, appending
    that node to the tail of the list.

    run-time O(n), space: O(n log n) 
    '''
    def depth_list2(self):

        return self.build_level(self.tree.root)  

    def build_level(self, node, level=0, levels=[]):
    
        lst_node = self.Node(node.data)

        if len(levels) == level:
            levels.append(lst_node)
        else:
            
            current, prev = levels[level], None

            while current != None:
                prev = current
                current = current.next

            prev.next = lst_node

        if node.left: self.build_level(node.left, level + 1, levels)
        if node.right: self.build_level(node.right, level + 1, levels)

        return levels

'''Check Balanced.

Implement a function to check if a binary tree is balanced.

For the purposes of this question, a balanced tree is defined to be a tree such
that the heights of the two subtrees of any node never differ by more than one.
'''

def is_balanced(tree):

    def leaf_count(node, count=0):

        if node == None: return count

        level_count = 0

        if node.left:
            level_count += leaf_count(node.left, count)
            level_count += 1
        
        if node.right:
            level_count -= leaf_count(node.right, count)
            level_count -= 1

        return level_count

    count = leaf_count(tree)

    return abs(leaf_count(tree)) <= 1

'''Validate BST.

Implement a function to check if a binary tree is a binary search tree.
'''

def is_bst(node):

    def check_bst(node, flr=None, ceil=None):

        if node == None: return True

        is_valid = False

        if (node.left == None or node.left.data < node.data) and (node.right == None or node.right.data > node.data):
            if (flr == None or flr < node.data) and (ceil == None or ceil > node.data):
                is_valid = True

        if node.left:
            is_valid &= check_bst(node.left, flr, node.data)

        if node.right:
            is_valid &= check_bst(node.right, node.data, ceil)

        return is_valid

    if node is None: return False

    return check_bst(node)

'''Successor.

Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree.

You may assume that each node has a link to its parent.
'''

def successor(tree, value):

    def path(tree, value):

        if tree == None: return None

        path = []

        while tree != None:

            path.append(tree)

            if tree.data == value:
                break
            elif tree.data >= value:
                tree = tree.left
            elif tree.data < value:
                tree = tree.right
        
        return path

    if tree == None or value == None: return None

    target_path = path(tree, value)
    
    target = target_path.pop()

    #  node does not exist
    if target == None or target.data != value: return None

    if target.right == None:
        # check the up-ward path
        target = target_path.pop()

        while target.data < value and target_path:
            target = target_path.pop()

        return target if target_path else None
    else:
        # traverse the right sub-tree
        nxt = target.right

        while nxt.left != None:
            nxt = nxt.left

        return nxt

'''First Common Ancestor:

Design an algorithm and write code to find the first common ancestor of two
nodes in a binary tree. Avoid storing additional nodes in a data structure.

NOTE: This is not necessarily a binary search tree.
'''

'''
Solution #1:

use DFS to find paths to p and q
take elements from both p and q while they are the same

return the last element that matches in both paths.
''' 
def first_common_ancestor1(tree, p, q):

    def find(tree, value, prev=[]):

        if tree == None: return None

        if tree.data == value:
            return prev + [tree.data]

        left = find(tree.left, value, prev + [tree.data])

        if left: return left

        right = find(tree.right, value, prev + [tree.data])

        if right: return right

    if not tree or not q or not p: return None

    p_path, q_path = find(tree, p), find(tree, q)

    if not (p_path and q_path): return None

    ancestor, index = None, 0
    
    while p_path[index] == q_path[index]:
        ancestor = p_path[index]
        index += 1

    return ancestor if ancestor else None

'''Check Subtree.

T1 and T2 are two very large binary trees, with T1 being much bigger
than T2. Create an algorithm to determine if T2 is a subtree of T1.

A tree T2 is a subtree of T1 if there exists a node n in T1 such that
the subtree of n is identical to T2. That is, if you cut off the
tree at node n, the two trees would be identical.
'''

def check_subtree1(t1, t2):

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

def check_subtree2(t1, t2):

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

        if left and not right:
            current.next = ListNode('-')
        if right and not left:
            tmp = head
            head = ListNode('-')
            head.next = tmp

        return head

    if not (t1 and t2): return False

    head1 = get_nodes(t1)
    head2 = get_nodes(t2)

    while head1 and head1.data != head2.data:
        head1 = head1.next

    exists = True

    while head2 != None:
        exists &= head1.data == head2.data

        head1, head2 = head1.next, head2.next

    return exists

'''Random Node.

You are implementing a binary tree class from scratch which, in
addition to insert, find, and delete, has a method getRandomNode()
which returns a random node from the tree. All nodes should be equally
likely to be chosen. Design and implement an algorithm for getRandomNode, 
and explain how you would implement the rest of the methods.
'''

from random import uniform

class RandomBinaryTree1():

    class TreeNode():

        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

        def is_full(self):
            return self.left and self.right

        def is_leaf(self):
            return not (self.left or self.right)

    def __init__(self):
        self.root = None

    def insert(self, data):
        
        def insertInOrder(node, data):
            if data <= node.data:

                if node.left == None:
                    node.left = self.TreeNode(data)
                else:
                    insertInOrder(node.left, data)
            else:

                if node.right == None:
                    node.right = self.TreeNode(data)
                else:
                    insertInOrder(node.right, data)
                
        if data == None: return None

        if self.root == None:
            self.root = self.TreeNode(data)
        else:
            insertInOrder(self.root, data)
            
    def find(self, value):
        
        def find_node(node, value):
            
            if node == None: 
                return None

            if node.data == value:
                return node

            left = find_node(node.left, value)

            if left: return left
 
            right = find_node(node.right, value)

            if right: return right
            
        if value == None: return None 

        return find_node(self.root, value)
    
    def delete(self, value):
        
        def delete_node(node, value, parent=None):

            if node == None: return

            if node.data == value:
                new_node = None

                if node.right and node.left:
                    new_node = node.right

                    current = node.right
                    prev = None

                    while current != None:
                        prev = current
                        current = current.left
                    
                    prev.left = node.left
                elif node.left and not node.right:
                    new_node = node.left
                elif not node.left and node.right:
                    new_node = node.right

                if parent == None:
                    self.root = new_node
                else:
                    
                    if node == parent.left:
                        parent.left = new_node
                    elif node == parent.right:
                        parent.right = new_node
    
            else:

                delete_node(node.left, value, node)
                delete_node(node.right, value, node)
                
                
        if value == None: return None

        return delete_node(self.root, value)

    def __get_values(self):

        def subvalues(node):

            if node == None: return

            values = []

            if node.left:
                values += subvalues(node.left)

            values += [node.data]

            if node.right:
                values += subvalues(node.right)
            
            return values

        if self.root == None: return []

        return subvalues(self.root)

    def get_random_node(self):
        
        if self.root == None: return None

        values = self.__get_values()

        index = int(uniform(0, len(values)))

        return values[index]

'''Paths with Sum.

You are given a binary tree in which each node contains an integer value
(which might be positive or negative). Design an algorithm to count the
number of of paths that sum to a given value. The path does not need to
start or end at the root or a leaf, but it must go downwards (traveling
only from parent nodes to child nodes).
'''

class SumTree1():

    class TreeNode():

        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

        def path_sums(self, value):
        
            def child_sums(node, parent_sum):
                
                if node == None: return

                path_sum = parent_sum + node.data

                sums = 1 if path_sum == value else 0

                if node.left:
                    sums += child_sums(node.left, path_sum)    

                if node.right:
                    sums += child_sums(node.right, path_sum)

                return sums

            sums = 1 if self.data == value else 0

            if self.left:
                sums += child_sums(self.left, self.data)
            
            if self.right:
                sums += child_sums(self.right, self.data)
            
            return sums

    def __init__(self):
        self.root = None
    
    def insert_at(self, node, value):
        
        if node == None: return

        if value <= node.data:
            node.left = self.TreeNode(value)
        elif value >= node.data:
            node.right = self.TreeNode(value)

    def insert(self, value):

        def insertInOrder(node, value):
            
            if node == None: return

            if value <= node.data:
                if node.left == None:
                    node.left = self.TreeNode(value)
                else:
                    insertInOrder(node.left, value)
            elif node.data < value:
                if node.right == None:
                    node.right = self.TreeNode(value)
                else:
                    insertInOrder(node.right, value)

        if self.root == None:
            self.root = self.TreeNode(value)
        else:
            insertInOrder(self.root, value)

'''BiNode.

Consider a simple data structure called BiNode, which has pointers
to two other nodes.

The data structure BiNode could be used to represent both a binary
tree (where node1 is the left node and node2 is the right node) or
a doubly linked list (where node1 is the previous node and node2
is the next node). Implement a method to convert a binary search
tree (implemented with BiNode) into a doubly linked list. The
values should be kept in order and the operation should be
performed in place (that is, on the original data structure).
'''

class TreeToList():

    class NodePair():

        def __init__(self, head=None, tail=None):
            self.head = head
            self.tail = tail

    class BiNode():

        def __init__(self, data=None, node1=None, node2=None):
            self.data = data
            self.node1 = node1
            self.node2 = node2

        def __str__(self):
            return f'{self.data}'

    def to_list(self, node):
        
        if not node: return None

        part1 = self.to_list(node.node1)
        part2 = self.to_list(node.node2)
        
        if part1:
            self.concat(part1.tail, node)

        if part2:
            self.concat(node, part2.head)

        return self.NodePair(node if not part1 else part1.head,
                    node if not part2 else part2.tail)

    @staticmethod
    def flatten(head):

        node = head.head

        arr = []
        while node:
            arr.append(node.data)
            node = node.node2

        return arr

    @staticmethod
    def concat(x, y):
        x.node2 = y
        y.node1 = x

    def build_tree(self, arr):

        n = len(arr)
        
        if n == 0: return None

        mid = n//2

        node = self.BiNode(arr[mid])

        if n > 0: node.node1 = self.build_tree(arr[:mid])
        if n > 1: node.node2 = self.build_tree(arr[mid + 1:])

        return node