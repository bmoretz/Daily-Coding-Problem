'''
652. Find Duplicate Subtrees

Example 1:

Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:

Input: root = [2,1,1]
Output: [[1]]
Example 3:

Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]

Constraints:

The number of the nodes in the tree will be in the range [1, 10^4]
-200 <= Node.val <= 200
'''

from collections import defaultdict, Counter

class Node:
    def __init__(self, val):
        self.value = val
        self.left, self.right = None, None

def build_tree(values):

    if not values:
        return None

    root = Node(values[0])
    values.pop(0)
    
    nodes = [root]

    it = iter(values)

    for val in it:
        parent = nodes[0]

        parent.left = Node(val)

        if parent.left.value != None:
            nodes += [parent.left]

        parent.right = Node(next(it, None))

        if parent.right.value != None:
            nodes += [parent.right]

        nodes.pop(0)

    return root

def findDuplicateSubtrees(values):
    
    root = build_tree(values)
    
    trees = defaultdict()
    trees.default_factory = len(trees)
    count = Counter()
    ans = []
    
    def lookup(node):
        if node:
            uid = trees[node.value, lookup(node.left), lookup(node.right)]
            count[uid] += 1
            if count[uid] == 2:
                ans.append(node)
            return uid

    lookup(root)

    return ans