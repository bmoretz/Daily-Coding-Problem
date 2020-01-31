'''1.30

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
'''

from problems.tree import populate_pre_order, Node

tree2 = ['a',
        ['a', [], []],
        ['a',
            ['a', [], []], 
            ['a', [], ['b']]
        ]]

tree = populate_pre_order(tree2)


def count_univariate2(tree):

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

val = count_univariate2(tree)

print(val)