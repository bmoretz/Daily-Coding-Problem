
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

class duplicate_subtrees:

    class Node:

        def __init__(self, val):
            self.value = val
            self.left, self.right = None, None

    def build_tree(self, values):

        if not values:
            return None

        root = self.Node(values[0])
        values.pop(0)
        
        nodes = [root]

        it = iter(values)

        for val in it:
            parent = nodes[0]

            parent.left = self.Node(val)

            if parent.left.value != None:
                nodes += [parent.left]

            parent.right = self.Node(next(it, None))

            if parent.right.value != None:
                nodes += [parent.right]

            nodes.pop(0)

        return root

    def findDuplicateSubtrees(self, values):
        
        root = self.build_tree(values)

        from collections import defaultdict, Counter
        
        trees = defaultdict()
        trees.default_factory = trees.__len__
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

values = [1,2,3,4,None,2,4,None,None,4]

sln = duplicate_subtrees().findDuplicateSubtrees( values )

print(sln)