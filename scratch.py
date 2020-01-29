from problems.tree import Node
from problems.tree import populate_pre_order
from problems.tree import get_height, get_width

''' 6.3

Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of +, -, * or /.

Given the root to such a tree, write a function to evalutate it.

For example, given the following tree:

        *
    +       -
3      2 4    5

Should return 45, as it is (3 + 2) * (4 + 5)
'''


arithmetic1 = ['*',
                ['+', [3], [2]],
                ['+', [4], [5]]]

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
         if isinstance( node.data, int ):
            return node.data
         else:
            return evaluate(node)

    def evaluate(root):
        if not root: return None

        operation = root.data
        
        left = eval_node(root.left)

        right = eval_node(root.right)
        
        return op(operation, left, right)

    return evaluate(root)

tree = populate_pre_order(arithmetic1)

val = evaluate1(tree)

print(val)
